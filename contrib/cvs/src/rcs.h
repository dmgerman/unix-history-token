begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $CVSid: @(#)rcs.h 1.18 94/09/23 $	 */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.4 kit.  *   * RCS source control definitions needed by rcs.c and friends  */
end_comment

begin_define
define|#
directive|define
name|RCS
value|"rcs"
end_define

begin_define
define|#
directive|define
name|RCS_CI
value|"ci"
end_define

begin_define
define|#
directive|define
name|RCS_CO
value|"co"
end_define

begin_define
define|#
directive|define
name|RCS_RLOG
value|"rlog"
end_define

begin_define
define|#
directive|define
name|RCS_DIFF
value|"rcsdiff"
end_define

begin_define
define|#
directive|define
name|RCS_RCSMERGE
value|"rcsmerge"
end_define

begin_define
define|#
directive|define
name|RCS_MERGE_PAT
value|"^>>>>>>> "
end_define

begin_comment
comment|/* runs "grep" with this pattern */
end_comment

begin_define
define|#
directive|define
name|RCSEXT
value|",v"
end_define

begin_define
define|#
directive|define
name|RCSPAT
value|"*,v"
end_define

begin_define
define|#
directive|define
name|RCSHEAD
value|"head"
end_define

begin_define
define|#
directive|define
name|RCSBRANCH
value|"branch"
end_define

begin_define
define|#
directive|define
name|RCSSYMBOLS
value|"symbols"
end_define

begin_define
define|#
directive|define
name|RCSDATE
value|"date"
end_define

begin_define
define|#
directive|define
name|RCSDESC
value|"desc"
end_define

begin_define
define|#
directive|define
name|RCSEXPAND
value|"expand"
end_define

begin_comment
comment|/* Used by the version of death support which resulted from old    versions of CVS (e.g. 1.5 if you define DEATH_SUPPORT and not    DEATH_STATE).  Only a hacked up RCS (used by those old versions of    CVS) will put this into RCS files.  Considered obsolete.  */
end_comment

begin_define
define|#
directive|define
name|RCSDEAD
value|"dead"
end_define

begin_define
define|#
directive|define
name|DATEFORM
value|"%02d.%02d.%02d.%02d.%02d.%02d"
end_define

begin_define
define|#
directive|define
name|SDATEFORM
value|"%d.%d.%d.%d.%d.%d"
end_define

begin_comment
comment|/*  * Opaque structure definitions used by RCS specific lookup routines  */
end_comment

begin_define
define|#
directive|define
name|VALID
value|0x1
end_define

begin_comment
comment|/* flags field contains valid data */
end_comment

begin_define
define|#
directive|define
name|INATTIC
value|0x2
end_define

begin_comment
comment|/* RCS file is located in the Attic */
end_comment

begin_define
define|#
directive|define
name|PARTIAL
value|0x4
end_define

begin_comment
comment|/* RCS file not completly parsed */
end_comment

begin_struct
struct|struct
name|rcsnode
block|{
name|int
name|refcount
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|head
decl_stmt|;
name|char
modifier|*
name|branch
decl_stmt|;
name|char
modifier|*
name|symbols_data
decl_stmt|;
name|char
modifier|*
name|expand
decl_stmt|;
name|List
modifier|*
name|symbols
decl_stmt|;
name|List
modifier|*
name|versions
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rcsnode
name|RCSNode
typedef|;
end_typedef

begin_struct
struct|struct
name|rcsversnode
block|{
name|char
modifier|*
name|version
decl_stmt|;
name|char
modifier|*
name|date
decl_stmt|;
name|char
modifier|*
name|author
decl_stmt|;
name|char
modifier|*
name|next
decl_stmt|;
name|int
name|dead
decl_stmt|;
name|List
modifier|*
name|branches
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rcsversnode
name|RCSVers
typedef|;
end_typedef

begin_comment
comment|/*  * CVS reserves all even-numbered branches for its own use.  "magic" branches  * (see rcs.c) are contained as virtual revision numbers (within symbolic  * tags only) off the RCS_MAGIC_BRANCH, which is 0.  CVS also reserves the  * ".1" branch for vendor revisions.  So, if you do your own branching, you  * should limit your use to odd branch numbers starting at 3.  */
end_comment

begin_define
define|#
directive|define
name|RCS_MAGIC_BRANCH
value|0
end_define

begin_comment
comment|/*  * exported interfaces  */
end_comment

begin_decl_stmt
name|RCSNode
modifier|*
name|RCS_parse
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|file
operator|,
specifier|const
name|char
operator|*
name|repos
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RCSNode
modifier|*
name|RCS_parsercsfile
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|rcsfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_check_kflag
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_getdate
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
name|char
operator|*
name|date
operator|,
name|int
name|force_tag_match
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_gettag
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
name|char
operator|*
name|symtag
operator|,
name|int
name|force_tag_match
operator|,
name|int
name|return_both
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_getversion
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|,
name|int
name|force_tag_match
operator|,
name|int
name|return_both
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_magicrev
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
name|char
operator|*
name|rev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|RCS_isbranch
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
specifier|const
name|char
operator|*
name|rev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|RCS_nodeisbranch
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
specifier|const
name|char
operator|*
name|tag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_whatbranch
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
specifier|const
name|char
operator|*
name|tag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_head
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|RCS_datecmp
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|date1
operator|,
name|char
operator|*
name|date2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|RCS_getrevtime
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
name|char
operator|*
name|rev
operator|,
name|char
operator|*
name|date
operator|,
name|int
name|fudge
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|RCS_symbols
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|RCS_check_tag
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|tag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|freercsnode
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
operator|*
name|rnodep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_getbranch
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
name|rcs
operator|,
name|char
operator|*
name|tag
operator|,
name|int
name|force_tag_match
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|RCS_isdead
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|RCS_getexpand
name|PROTO
argument_list|(
operator|(
name|RCSNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

