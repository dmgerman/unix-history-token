begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Graph coloring register allocator    Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Michael Matz<matz@suse.de>    and Daniel Berlin<dan@cgsoftware.com>.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under the    terms of the GNU General Public License as published by the Free Software    Foundation; either version 2, or (at your option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more    details.     You should have received a copy of the GNU General Public License along    with GCC; see the file COPYING.  If not, write to the Free Software    Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Double linked list to implement the per-type lists of webs    and moves.  */
end_comment

begin_struct
struct|struct
name|dlist
block|{
name|struct
name|dlist
modifier|*
name|prev
decl_stmt|;
name|struct
name|dlist
modifier|*
name|next
decl_stmt|;
union|union
block|{
name|struct
name|web
modifier|*
name|web
decl_stmt|;
name|struct
name|move
modifier|*
name|move
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Simple helper macros for ease of misuse.  */
end_comment

begin_define
define|#
directive|define
name|DLIST_WEB
parameter_list|(
name|l
parameter_list|)
value|((l)->value.web)
end_define

begin_define
define|#
directive|define
name|DLIST_MOVE
parameter_list|(
name|l
parameter_list|)
value|((l)->value.move)
end_define

begin_comment
comment|/* Classification of a given node (i.e. what state it's in).  */
end_comment

begin_enum
enum|enum
name|node_type
block|{
name|INITIAL
init|=
literal|0
block|,
name|FREE
block|,
name|PRECOLORED
block|,
name|SIMPLIFY
block|,
name|SIMPLIFY_SPILL
block|,
name|SIMPLIFY_FAT
block|,
name|FREEZE
block|,
name|SPILL
block|,
name|SELECT
block|,
name|SPILLED
block|,
name|COALESCED
block|,
name|COLORED
block|,
name|LAST_NODE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/* A list of conflict bitmaps, factorized on the exact part of    the source, which conflicts with the DEFs, whose ID are noted in    the bitmap.  This is used while building web-parts with conflicts.  */
end_comment

begin_struct
struct|struct
name|tagged_conflict
block|{
name|struct
name|tagged_conflict
modifier|*
name|next
decl_stmt|;
name|bitmap
name|conflicts
decl_stmt|;
comment|/* If the part of source identified by size S, byteoffset O conflicts,      then size_word == S | (O<< 16).  */
name|unsigned
name|int
name|size_word
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Such a structure is allocated initially for each def and use.    In the process of building the interference graph web parts are    connected together, if they have common instructions and reference the    same register.  That way live ranges are build (by connecting defs and    uses) and implicitly complete webs (by connecting web parts in common    uses).  */
end_comment

begin_struct
struct|struct
name|web_part
block|{
comment|/* The def or use for this web part.  */
name|struct
name|ref
modifier|*
name|ref
decl_stmt|;
comment|/* The uplink implementing the disjoint set.  */
name|struct
name|web_part
modifier|*
name|uplink
decl_stmt|;
comment|/* Here dynamic information associated with each def/use is saved.      This all is only valid for root web parts (uplink==NULL).      That's the information we need to merge, if web parts are unioned.  */
comment|/* Number of spanned insns containing any deaths.  */
name|unsigned
name|int
name|spanned_deaths
decl_stmt|;
comment|/* The list of bitmaps of DEF ID's with which this part conflicts.  */
name|struct
name|tagged_conflict
modifier|*
name|sub_conflicts
decl_stmt|;
comment|/* If there's any call_insn, while this part is live.  */
name|unsigned
name|int
name|crosses_call
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Web structure used to store info about connected live ranges.    This represents the nodes of the interference graph, which gets    colored.  It can also hold subwebs, which are contained in webs    and represent subregs.  */
end_comment

begin_struct
struct|struct
name|web
block|{
comment|/* Unique web ID.  */
name|unsigned
name|int
name|id
decl_stmt|;
comment|/* Register number of the live range's variable.  */
name|unsigned
name|int
name|regno
decl_stmt|;
comment|/* How many insns containing deaths do we span?  */
name|unsigned
name|int
name|span_deaths
decl_stmt|;
comment|/* Spill_temp indicates if this web was part of a web spilled in the      last iteration, or or reasons why this shouldn't be spilled again.      1 spill web, can't be spilled.      2 big spill web (live over some deaths).  Discouraged, but not        impossible to spill again.      3 short web (spans no deaths), can't be spilled.  */
name|unsigned
name|int
name|spill_temp
decl_stmt|;
comment|/* When coalescing we might change spill_temp.  If breaking aliases we      need to restore it.  */
name|unsigned
name|int
name|orig_spill_temp
decl_stmt|;
comment|/* Cost of spilling.  */
name|unsigned
name|HOST_WIDE_INT
name|spill_cost
decl_stmt|;
name|unsigned
name|HOST_WIDE_INT
name|orig_spill_cost
decl_stmt|;
comment|/* How many webs are aliased to us?  */
name|unsigned
name|int
name|num_aliased
decl_stmt|;
comment|/* The color we got.  This is a hardreg number.  */
name|int
name|color
decl_stmt|;
comment|/* 1 + the color this web got in the last pass.  If it hadn't got a color,      or we are in the first pass, or this web is a new one, this is zero.  */
name|int
name|old_color
decl_stmt|;
comment|/* Now follow some flags characterizing the web.  */
comment|/* Nonzero, if we should use usable_regs for this web, instead of      preferred_class() or alternate_class().  */
name|unsigned
name|int
name|use_my_regs
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if we selected this web as possible spill candidate in      select_spill().  */
name|unsigned
name|int
name|was_spilled
range|:
literal|1
decl_stmt|;
comment|/* We need to distinguish also webs which are targets of coalescing      (all x with some y, so that x==alias(y)), but the alias field is      only set for sources of coalescing.  This flag is set for all webs      involved in coalescing in some way.  */
name|unsigned
name|int
name|is_coalesced
range|:
literal|1
decl_stmt|;
comment|/* Nonzero, if this web (or subweb) doesn't correspond with any of      the current functions actual use of reg rtx.  Happens e.g. with      conflicts to a web, of which only a part was still undefined at the      point of that conflict.  In this case we construct a subweb      representing these yet undefined bits to have a target for the      conflict.  Suppose e.g. this sequence:      (set (reg:DI x) ...)      (set (reg:SI y) ...)      (set (subreg:SI (reg:DI x) 0) ...)      (use (reg:DI x))      Here x only partly conflicts with y.  Namely only (subreg:SI (reg:DI x)      1) conflicts with it, but this rtx doesn't show up in the program.  For      such things an "artificial" subweb is built, and this flag is true for      them.  */
name|unsigned
name|int
name|artificial
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if we span a call_insn.  */
name|unsigned
name|int
name|crosses_call
range|:
literal|1
decl_stmt|;
comment|/* Wether the web is involved in a move insn.  */
name|unsigned
name|int
name|move_related
range|:
literal|1
decl_stmt|;
comment|/* 1 when this web (or parts thereof) are live over an abnormal edge.  */
name|unsigned
name|int
name|live_over_abnormal
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this web is used in subregs where the mode change      was illegal for hardregs in CLASS_CANNOT_CHANGE_MODE.  */
name|unsigned
name|int
name|mode_changed
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if some references of this web, where in subreg context,      but the actual subreg is already stripped (i.e. we don't know the      outer mode of the actual reference).  */
name|unsigned
name|int
name|subreg_stripped
range|:
literal|1
decl_stmt|;
comment|/* Nonzero, when this web stems from the last pass of the allocator,      and all info is still valid (i.e. it wasn't spilled).  */
name|unsigned
name|int
name|old_web
range|:
literal|1
decl_stmt|;
comment|/* Used in rewrite_program2() to remember webs, which      are already marked for (re)loading.  */
name|unsigned
name|int
name|in_load
range|:
literal|1
decl_stmt|;
comment|/* If in_load is != 0, then this is nonzero, if only one use was seen      since insertion in loadlist.  Zero if more uses currently need a      reload.  Used to differentiate between inserting register loads or      directly substituting the stackref.  */
name|unsigned
name|int
name|one_load
range|:
literal|1
decl_stmt|;
comment|/* When using rewrite_program2() this flag gets set if some insns      were inserted on behalf of this web.  IR spilling might ignore some      deaths up to the def, so no code might be emitted and we need not to      spill such a web again.  */
name|unsigned
name|int
name|changed
range|:
literal|1
decl_stmt|;
comment|/* With interference region spilling it's sometimes the case, that a      bb border is also an IR border for webs, which were targets of moves,      which are already removed due to coalescing.  All webs, which are      a destination of such a removed move, have this flag set.  */
name|unsigned
name|int
name|target_of_spilled_move
range|:
literal|1
decl_stmt|;
comment|/* For optimistic coalescing we need to be able to break aliases, which      includes restoring conflicts to those before coalescing.  This flag      is set, if we have a list of conflicts before coalescing.  It's needed      because that list is lazily constructed only when actually needed.  */
name|unsigned
name|int
name|have_orig_conflicts
range|:
literal|1
decl_stmt|;
comment|/* Current state of the node.  */
name|ENUM_BITFIELD
argument_list|(
argument|node_type
argument_list|)
name|type
label|:
literal|5
expr_stmt|;
comment|/* A regclass, combined from preferred and alternate class, or calculated      from usable_regs.  Used only for debugging, and to determine      add_hardregs.  */
name|ENUM_BITFIELD
argument_list|(
argument|reg_class
argument_list|)
name|regclass
label|:
literal|10
expr_stmt|;
comment|/* Additional consecutive hardregs needed for this web.  */
name|int
name|add_hardregs
decl_stmt|;
comment|/* Number of conflicts currently.  */
name|int
name|num_conflicts
decl_stmt|;
comment|/* Numbers of uses and defs, which belong to this web.  */
name|unsigned
name|int
name|num_uses
decl_stmt|;
name|unsigned
name|int
name|num_defs
decl_stmt|;
comment|/* The (reg:M a) or (subreg:M1 (reg:M2 a) x) rtx which this      web is based on.  This is used to distinguish subreg webs      from it's reg parents, and to get hold of the mode.  */
name|rtx
name|orig_x
decl_stmt|;
comment|/* If this web is a subweb, this point to the super web.  Otherwise      it's NULL.  */
name|struct
name|web
modifier|*
name|parent_web
decl_stmt|;
comment|/* If this web is a subweb, but not the last one, this points to the      next subweb of the same super web.  Otherwise it's NULL.  */
name|struct
name|web
modifier|*
name|subreg_next
decl_stmt|;
comment|/* The set of webs (or subwebs), this web conflicts with.  */
name|struct
name|conflict_link
modifier|*
name|conflict_list
decl_stmt|;
comment|/* If have_orig_conflicts is set this contains a copy of conflict_list,      as it was right after building the interference graph.      It's used for incremental i-graph building and for breaking      coalescings again.  */
name|struct
name|conflict_link
modifier|*
name|orig_conflict_list
decl_stmt|;
comment|/* Bitmap of all conflicts which don't count this pass, because of      non-intersecting hardregs of the conflicting webs.  See also      record_conflict().  */
name|bitmap
name|useless_conflicts
decl_stmt|;
comment|/* Different sets of hard registers, for all usable registers, ...  */
name|HARD_REG_SET
name|usable_regs
decl_stmt|;
comment|/* ... the same before coalescing, ...  */
name|HARD_REG_SET
name|orig_usable_regs
decl_stmt|;
comment|/* ... colors of all already colored neighbors (used when biased coloring      is active), and ...  */
name|HARD_REG_SET
name|bias_colors
decl_stmt|;
comment|/* ... colors of PRECOLORED webs this web is connected to by a move.  */
name|HARD_REG_SET
name|prefer_colors
decl_stmt|;
comment|/* Number of usable colors in usable_regs.  */
name|int
name|num_freedom
decl_stmt|;
comment|/* After successful coloring the graph each web gets a new reg rtx,      with which the original uses and defs are replaced.  This is it.  */
name|rtx
name|reg_rtx
decl_stmt|;
comment|/* While spilling this is the rtx of the home of spilled webs.      It can be a mem ref (a stack slot), or a pseudo register.  */
name|rtx
name|stack_slot
decl_stmt|;
comment|/* Used in rewrite_program2() to remember the using      insn last seen for webs needing (re)loads.  */
name|rtx
name|last_use_insn
decl_stmt|;
comment|/* If this web is rematerializable, this contains the RTL pattern      usable as source for that.  Otherwise it's NULL.  */
name|rtx
name|pattern
decl_stmt|;
comment|/* All the defs and uses.  There are num_defs, resp.      num_uses elements.  */
name|struct
name|ref
modifier|*
modifier|*
name|defs
decl_stmt|;
comment|/* [0..num_defs-1] */
name|struct
name|ref
modifier|*
modifier|*
name|uses
decl_stmt|;
comment|/* [0..num_uses-1] */
comment|/* The web to which this web is aliased (coalesced).  If NULL, this      web is not coalesced into some other (but might still be a target      for other webs).  */
name|struct
name|web
modifier|*
name|alias
decl_stmt|;
comment|/* With iterated coalescing this is a list of active moves this web      is involved in.  */
name|struct
name|move_list
modifier|*
name|moves
decl_stmt|;
comment|/* The list implementation.  */
name|struct
name|dlist
modifier|*
name|dlink
decl_stmt|;
comment|/* While building webs, out of web-parts, this holds a (partial)      list of all refs for this web seen so far.  */
name|struct
name|df_link
modifier|*
name|temp_refs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For implementing a single linked list.  */
end_comment

begin_struct
struct|struct
name|web_link
block|{
name|struct
name|web_link
modifier|*
name|next
decl_stmt|;
name|struct
name|web
modifier|*
name|web
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A subconflict is part of a conflict edge to track precisely,    which parts of two webs conflict, in case not all of both webs do.  */
end_comment

begin_struct
struct|struct
name|sub_conflict
block|{
comment|/* The next partial conflict.  For one such list the parent-web of      all the S webs, resp. the parent of all the T webs are constant.  */
name|struct
name|sub_conflict
modifier|*
name|next
decl_stmt|;
name|struct
name|web
modifier|*
name|s
decl_stmt|;
name|struct
name|web
modifier|*
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This represents an edge in the conflict graph.  */
end_comment

begin_struct
struct|struct
name|conflict_link
block|{
name|struct
name|conflict_link
modifier|*
name|next
decl_stmt|;
comment|/* The web we conflict with (the Target of the edge).  */
name|struct
name|web
modifier|*
name|t
decl_stmt|;
comment|/* If not the complete source web and T conflict, this points to      the list of parts which really conflict.  */
name|struct
name|sub_conflict
modifier|*
name|sub
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For iterated coalescing the moves can be in these states.  */
end_comment

begin_enum
enum|enum
name|move_type
block|{
name|WORKLIST
block|,
name|MV_COALESCED
block|,
name|CONSTRAINED
block|,
name|FROZEN
block|,
name|ACTIVE
block|,
name|LAST_MOVE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/* Structure of a move we are considering coalescing.  */
end_comment

begin_struct
struct|struct
name|move
block|{
name|rtx
name|insn
decl_stmt|;
name|struct
name|web
modifier|*
name|source_web
decl_stmt|;
name|struct
name|web
modifier|*
name|target_web
decl_stmt|;
name|enum
name|move_type
name|type
decl_stmt|;
name|struct
name|dlist
modifier|*
name|dlink
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* List of moves.  */
end_comment

begin_struct
struct|struct
name|move_list
block|{
name|struct
name|move_list
modifier|*
name|next
decl_stmt|;
name|struct
name|move
modifier|*
name|move
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* To have fast access to the defs and uses per insn, we have one such    structure per insn.  The difference to the normal df.c structures is,    that it doesn't contain any NULL refs, which df.c produces in case    an insn was modified and it only contains refs to pseudo regs, or to    hardregs which matter for allocation, i.e. those not in    never_use_colors.  */
end_comment

begin_struct
struct|struct
name|ra_insn_info
block|{
name|unsigned
name|int
name|num_defs
decl_stmt|,
name|num_uses
decl_stmt|;
name|struct
name|ref
modifier|*
modifier|*
name|defs
decl_stmt|,
modifier|*
modifier|*
name|uses
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The above structures are stored in this array, indexed by UID...  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ra_insn_info
modifier|*
name|insn_df
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ... and the size of that array, as we add insn after setting it up.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|insn_df_max_uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The interference graph.  */
end_comment

begin_decl_stmt
specifier|extern
name|sbitmap
name|igraph
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And how to access it.  I and J are web indices.  If the bit    igraph_index(I, J) is set, then they conflict.  Note, that    if only parts of webs conflict, then also only those parts    are noted in the I-graph (i.e. the parent webs not).  */
end_comment

begin_define
define|#
directive|define
name|igraph_index
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
value|((i)< (j) ? ((j)*((j)-1)/2)+(i) : ((i)*((i)-1)/2)+(j))
end_define

begin_comment
comment|/* This is the bitmap of all (even partly) conflicting super webs.    If bit I*num_webs+J or J*num_webs+I is set, then I and J (both being    super web indices) conflict, maybe only partially.  Note the    asymmetry.  */
end_comment

begin_decl_stmt
specifier|extern
name|sbitmap
name|sup_igraph
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After the first pass, and when interference region spilling is    activated, bit I is set, when the insn with UID I contains some    refs to pseudos which die at the insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|sbitmap
name|insns_with_deaths
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The size of that sbitmap.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|death_insns_max_uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All the web-parts.  There are exactly as many web-parts as there    are register refs in the insn stream.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|web_part
modifier|*
name|web_parts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of all webs, including subwebs.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|num_webs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of just the subwebs.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|num_subwebs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of all webs, including subwebs.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|num_allwebs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For easy access when given a web ID: id2web[W->id] == W.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|web
modifier|*
modifier|*
name|id2web
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each hardreg, the web which represents it.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|web
modifier|*
name|hardreg2web
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given the ID of a df_ref, which represent a DEF, def2web[ID] is    the web, to which this def belongs.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|web
modifier|*
modifier|*
name|def2web
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The same as def2web, just for uses.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|web
modifier|*
modifier|*
name|use2web
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of all recognized and coalescable move insns.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|move_list
modifier|*
name|wl_moves
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some parts of the compiler which we run after colorizing    clean reg_renumber[], so we need another place for the colors.    This is copied to reg_renumber[] just before returning to toplev.  */
end_comment

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|ra_reg_renumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The size of that array.  Some passes after coloring might have created    new pseudos, which will get no color.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ra_max_regno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The dataflow structure of the current function, while regalloc    runs.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|df
modifier|*
name|df
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each basic block B we have a bitmap of DF_REF_ID's of uses,    which backward reach the end of B.  */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap
modifier|*
name|live_at_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One pass is: collecting registers refs, building I-graph, spilling.    And this is how often we already ran that for the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ra_pass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The maximum pseudo regno, just before register allocation starts.    While regalloc runs all pseudos with a larger number represent    potentially stack slots or hardregs.  I call them stackwebs or    stackpseudos.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|max_normal_pseudo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One of the fixed colors.  It must be< FIRST_PSEUDO_REGISTER, because    we sometimes want to check the color against a HARD_REG_SET.  It must    be>= 0, because negative values mean "no color".    This color is used for the above stackwebs, when they can't be colored.    I.e. normally they would be spilled, but they already represent    stackslots.  So they are colored with an invalid color.  It has    the property that even webs which conflict can have that color at the    same time.  I.e. a stackweb with that color really represents a    stackslot.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|an_unusable_color
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* While building the I-graph, every time insn UID is looked at,    number_seen[UID] is incremented.  For debugging.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|number_seen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The different lists on which a web can be (based on the type).  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|dlist
modifier|*
name|web_lists
index|[
operator|(
name|int
operator|)
name|LAST_NODE_TYPE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WEBS
parameter_list|(
name|type
parameter_list|)
value|(web_lists[(int)(type)])
end_define

begin_comment
comment|/* The largest DF_REF_ID of defs resp. uses, as it was in the    last pass.  In the first pass this is zero.  Used to distinguish new    from old references.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|last_def_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|last_use_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Similar for UIDs and number of webs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|last_max_uid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|last_num_webs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If I is the ID of an old use, and last_check_uses[I] is set,    then we must reevaluate it's flow while building the new I-graph.  */
end_comment

begin_decl_stmt
specifier|extern
name|sbitmap
name|last_check_uses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If nonzero, record_conflict() saves the current conflict list of    webs in orig_conflict_list, when not already done so, and the conflict    list is going to be changed.  It is set, after initially building the    I-graph.  I.e. new conflicts due to coalescing trigger that copying.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|remember_conflicts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The maximum UID right before calling regalloc().    Used to detect any instructions inserted by the allocator.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|orig_max_uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A HARD_REG_SET of those color, which can't be used for coalescing.    Includes e.g. fixed_regs.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|never_use_colors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each class C this is reg_class_contents[C] \ never_use_colors.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|usable_regs
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each class C the count of hardregs in usable_regs[C].  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|num_free_regs
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each mode M the hardregs, which are MODE_OK for M, and have    enough space behind them to hold an M value.  Additionally    if reg R is OK for mode M, but it needs two hardregs, then R+1 will    also be set here, even if R+1 itself is not OK for M.  I.e. this    represent the possible resources which could be taken away be a value    in mode M.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|hardregs_for_mode
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The set of hardregs, for which _any_ mode change is invalid.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|invalid_mode_change_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For 0<= I<= 255, the number of bits set in I.  Used to calculate    the number of set bits in a HARD_REG_SET.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|byte2bitcount
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expressive helper macros.  */
end_comment

begin_define
define|#
directive|define
name|ID2WEB
parameter_list|(
name|I
parameter_list|)
value|id2web[I]
end_define

begin_define
define|#
directive|define
name|NUM_REGS
parameter_list|(
name|W
parameter_list|)
value|(((W)->type == PRECOLORED) ? 1 : (W)->num_freedom)
end_define

begin_define
define|#
directive|define
name|SUBWEB_P
parameter_list|(
name|W
parameter_list|)
value|(GET_CODE ((W)->orig_x) == SUBREG)
end_define

begin_comment
comment|/* Constant usable as debug area to ra_debug_msg.  */
end_comment

begin_define
define|#
directive|define
name|DUMP_COSTS
value|0x0001
end_define

begin_define
define|#
directive|define
name|DUMP_WEBS
value|0x0002
end_define

begin_define
define|#
directive|define
name|DUMP_IGRAPH
value|0x0004
end_define

begin_define
define|#
directive|define
name|DUMP_PROCESS
value|0x0008
end_define

begin_define
define|#
directive|define
name|DUMP_COLORIZE
value|0x0010
end_define

begin_define
define|#
directive|define
name|DUMP_ASM
value|0x0020
end_define

begin_define
define|#
directive|define
name|DUMP_CONSTRAINTS
value|0x0040
end_define

begin_define
define|#
directive|define
name|DUMP_RESULTS
value|0x0080
end_define

begin_define
define|#
directive|define
name|DUMP_DF
value|0x0100
end_define

begin_define
define|#
directive|define
name|DUMP_RTL
value|0x0200
end_define

begin_define
define|#
directive|define
name|DUMP_FINAL_RTL
value|0x0400
end_define

begin_define
define|#
directive|define
name|DUMP_REGCLASS
value|0x0800
end_define

begin_define
define|#
directive|define
name|DUMP_SM
value|0x1000
end_define

begin_define
define|#
directive|define
name|DUMP_LAST_FLOW
value|0x2000
end_define

begin_define
define|#
directive|define
name|DUMP_LAST_RTL
value|0x4000
end_define

begin_define
define|#
directive|define
name|DUMP_REBUILD
value|0x8000
end_define

begin_define
define|#
directive|define
name|DUMP_IGRAPH_M
value|0x10000
end_define

begin_define
define|#
directive|define
name|DUMP_VALIDIFY
value|0x20000
end_define

begin_define
define|#
directive|define
name|DUMP_EVER
value|((unsigned int)-1)
end_define

begin_define
define|#
directive|define
name|DUMP_NEARLY_EVER
value|(DUMP_EVER - DUMP_COSTS - DUMP_IGRAPH_M)
end_define

begin_comment
comment|/* All the wanted debug levels as ORing of the various DUMP_xxx    constants.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|debug_new_regalloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we want biased coloring.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_biased
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to use improved (and slow) spilling.  This    includes also interference region spilling (see below).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_improved_spilling
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for using interference region spilling.  Zero for improved    Chaintin style spilling (only at deaths).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_ir_spilling
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we use optimistic coalescing, zero for iterated    coalescing.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_optimistic_coalescing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to break aliases of spilled webs.  Forced to    nonzero, when flag_ra_optimistic_coalescing is.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_break_aliases
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to merge the spill costs of webs which    are coalesced.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_merge_spill_costs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to spill at every use, instead of at deaths,    or interference region borders.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_spill_every_use
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to output all notes in the debug dumps.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ra_dump_notes
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
modifier|*
name|ra_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|ra_calloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hard_regs_count
parameter_list|(
name|HARD_REG_SET
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|ra_emit_move_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|ra_debug_msg
argument_list|(
name|unsigned
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|hard_regs_intersect_p
parameter_list|(
name|HARD_REG_SET
modifier|*
parameter_list|,
name|HARD_REG_SET
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|rtx_to_bits
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|web
modifier|*
name|find_subweb
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|web
modifier|*
name|find_subweb_2
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|web
modifier|*
name|find_web_for_subweb_1
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|find_web_for_subweb
parameter_list|(
name|w
parameter_list|)
value|(((w)->parent_web) \ 				? find_web_for_subweb_1 ((w)->parent_web) \ 				: (w))
end_define

begin_function_decl
specifier|extern
name|void
name|ra_build_realloc
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_build_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_build_free_all
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_colorize_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_colorize_free_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_rewrite_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_print_rtx
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_print_rtx_top
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_debug_rtx
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_debug_insns
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_debug_bbi
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_print_rtl_with_bb
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_igraph
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_igraph_machine
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_constraints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_cost
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_graph_cost
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_ra
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_number_seen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_static_insn_cost
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_web_conflicts
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_web_insns
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|web_conflicts_p
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|,
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_hard_reg_set
parameter_list|(
name|HARD_REG_SET
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_list
parameter_list|(
name|struct
name|dlist
modifier|*
parameter_list|,
name|struct
name|dlist
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dlist
modifier|*
name|pop_list
parameter_list|(
name|struct
name|dlist
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_conflict
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|,
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memref_is_stack_slot
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_i_graph
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_web
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|,
name|enum
name|node_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_web_from_list
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reset_lists
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|web
modifier|*
name|alias
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|merge_moves
parameter_list|(
name|struct
name|web
modifier|*
parameter_list|,
name|struct
name|web
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ra_colorize_graph
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|actual_spill
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emit_colors
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_moves
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setup_renumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_suspicious_death_notes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

