begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Name/value lists.  Values can be strings or pointers and/or can carry  * integers.  The names can be NULL, resulting in simple value lists.  */
end_comment

begin_struct
struct|struct
name|nvlist
block|{
name|struct
name|nvlist
modifier|*
name|nv_next
decl_stmt|;
specifier|const
name|char
modifier|*
name|nv_name
decl_stmt|;
union|union
block|{
specifier|const
name|char
modifier|*
name|un_str
decl_stmt|;
name|void
modifier|*
name|un_ptr
decl_stmt|;
block|}
name|nv_un
union|;
define|#
directive|define
name|nv_str
value|nv_un.un_str
define|#
directive|define
name|nv_ptr
value|nv_un.un_ptr
name|int
name|nv_int
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Kernel configurations.  */
end_comment

begin_struct
struct|struct
name|config
block|{
name|struct
name|config
modifier|*
name|cf_next
decl_stmt|;
comment|/* linked list */
specifier|const
name|char
modifier|*
name|cf_name
decl_stmt|;
comment|/* "vmunix" */
name|int
name|cf_lineno
decl_stmt|;
comment|/* source line */
name|struct
name|nvlist
modifier|*
name|cf_root
decl_stmt|;
comment|/* "root on ra0a" */
name|struct
name|nvlist
modifier|*
name|cf_swap
decl_stmt|;
comment|/* "swap on ra0b and ra1b" */
name|struct
name|nvlist
modifier|*
name|cf_dump
decl_stmt|;
comment|/* "dumps on ra0b" */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attributes.  These come in two flavors: "plain" and "interface".  * Plain attributes (e.g., "ether") simply serve to pull in files.  * Interface attributes (e.g., "scsi") carry three lists: locators,  * child devices, and references.  The locators are those things  * that must be specified in order to configure a device instance  * using this attribute (e.g., "tg0 at scsi0").  The a_devs field  * lists child devices that can connect here (e.g., "tg"s), while  * the a_refs are parents that carry the attribute (e.g., actual  * SCSI host adapter drivers such as the SPARC "esp").  */
end_comment

begin_struct
struct|struct
name|attr
block|{
specifier|const
name|char
modifier|*
name|a_name
decl_stmt|;
comment|/* name of this attribute */
name|int
name|a_iattr
decl_stmt|;
comment|/* true => allows children */
name|struct
name|nvlist
modifier|*
name|a_locs
decl_stmt|;
comment|/* locators required */
name|int
name|a_loclen
decl_stmt|;
comment|/* length of above list */
name|struct
name|nvlist
modifier|*
name|a_devs
decl_stmt|;
comment|/* children */
name|struct
name|nvlist
modifier|*
name|a_refs
decl_stmt|;
comment|/* parents */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The "base" part of a device ("uba", "sd"; but not "uba2" or  * "sd0").  It may be found "at" one or more attributes, including  * "at root" (this is represented by a NULL attribute).  *  * Each device may also export attributes.  If any provide an output  * interface (e.g., "esp" provides "scsi"), other devices (e.g.,  * "tg"s) can be found at instances of this one (e.g., "esp"s).  * Such a connection must provide locators as specified by that  * interface attribute (e.g., "target").  *  * Each base carries a list of instances (via d_ihead).  Note that this  * list "skips over" aliases; those must be found through the instances  * themselves.  */
end_comment

begin_struct
struct|struct
name|devbase
block|{
specifier|const
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* e.g., "sd" */
name|struct
name|devbase
modifier|*
name|d_next
decl_stmt|;
comment|/* linked list */
name|int
name|d_isdef
decl_stmt|;
comment|/* set once properly defined */
name|int
name|d_ispseudo
decl_stmt|;
comment|/* is a pseudo-device */
name|int
name|d_major
decl_stmt|;
comment|/* used for "root on sd0", e.g. */
name|struct
name|nvlist
modifier|*
name|d_atlist
decl_stmt|;
comment|/* e.g., "at tg" (attr list) */
name|struct
name|nvlist
modifier|*
name|d_vectors
decl_stmt|;
comment|/* interrupt vectors, if any */
name|struct
name|nvlist
modifier|*
name|d_attrs
decl_stmt|;
comment|/* attributes, if any */
name|struct
name|devi
modifier|*
name|d_ihead
decl_stmt|;
comment|/* first instance, if any */
name|struct
name|devi
modifier|*
modifier|*
name|d_ipp
decl_stmt|;
comment|/* used for tacking on more instances */
name|int
name|d_umax
decl_stmt|;
comment|/* highest unit number + 1 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An "instance" of a device.  The same instance may be listed more  * than once, e.g., "xx0 at isa? port FOO" + "xx0 at isa? port BAR".  *  * After everything has been read in and verified, the devi's are  * "packed" to collect all the information needed to generate ioconf.c.  * In particular, we try to collapse multiple aliases into a single entry.  * We then assign each "primary" (non-collapsed) instance a cfdata index.  * Note that there may still be aliases among these.  */
end_comment

begin_struct
struct|struct
name|devi
block|{
comment|/* created while parsing config file */
specifier|const
name|char
modifier|*
name|i_name
decl_stmt|;
comment|/* e.g., "sd0" */
name|int
name|i_unit
decl_stmt|;
comment|/* unit from name, e.g., 0 */
name|struct
name|devbase
modifier|*
name|i_base
decl_stmt|;
comment|/* e.g., pointer to "sd" base */
name|struct
name|devi
modifier|*
name|i_next
decl_stmt|;
comment|/* list of all instances */
name|struct
name|devi
modifier|*
name|i_bsame
decl_stmt|;
comment|/* list on same base */
name|struct
name|devi
modifier|*
name|i_alias
decl_stmt|;
comment|/* other aliases of this instance */
specifier|const
name|char
modifier|*
name|i_at
decl_stmt|;
comment|/* where this is "at" (NULL if at root) */
name|struct
name|attr
modifier|*
name|i_atattr
decl_stmt|;
comment|/* attr that allowed attach */
name|struct
name|devbase
modifier|*
name|i_atdev
decl_stmt|;
comment|/* dev if "at<devname><unit>", else NULL */
specifier|const
name|char
modifier|*
modifier|*
name|i_locs
decl_stmt|;
comment|/* locators (as given by i_atattr) */
name|int
name|i_atunit
decl_stmt|;
comment|/* unit from "at" */
name|int
name|i_cfflags
decl_stmt|;
comment|/* flags from config line */
name|int
name|i_lineno
decl_stmt|;
comment|/* line # in config, for later errors */
comment|/* created during packing or ioconf.c generation */
comment|/* 		i_loclen	   via i_atattr->a_loclen */
name|short
name|i_collapsed
decl_stmt|;
comment|/* set => this alias no longer needed */
name|short
name|i_cfindex
decl_stmt|;
comment|/* our index in cfdata */
name|short
name|i_pvlen
decl_stmt|;
comment|/* number of parents */
name|short
name|i_pvoff
decl_stmt|;
comment|/* offset in parents.vec */
name|short
name|i_locoff
decl_stmt|;
comment|/* offset in locators.vec */
name|short
name|i_ivoff
decl_stmt|;
comment|/* offset in interrupt vectors, if any */
name|struct
name|devi
modifier|*
modifier|*
name|i_parents
decl_stmt|;
comment|/* the parents themselves */
block|}
struct|;
end_struct

begin_comment
comment|/* special units */
end_comment

begin_define
define|#
directive|define
name|STAR
value|(-1)
end_define

begin_comment
comment|/* unit number for, e.g., "sd*" */
end_comment

begin_define
define|#
directive|define
name|WILD
value|(-2)
end_define

begin_comment
comment|/* unit number for, e.g., "sd?" */
end_comment

begin_comment
comment|/*  * Files.  Each file is either standard (always included) or optional,  * depending on whether it has names on which to *be* optional.  */
end_comment

begin_struct
struct|struct
name|files
block|{
name|struct
name|files
modifier|*
name|fi_next
decl_stmt|;
comment|/* linked list */
specifier|const
name|char
modifier|*
name|fi_srcfile
decl_stmt|;
comment|/* the name of the "files" file that got us */
name|u_short
name|fi_srcline
decl_stmt|;
comment|/* and the line number */
name|u_char
name|fi_flags
decl_stmt|;
comment|/* as below */
name|char
name|fi_lastc
decl_stmt|;
comment|/* last char from path */
specifier|const
name|char
modifier|*
name|fi_path
decl_stmt|;
comment|/* full file path */
specifier|const
name|char
modifier|*
name|fi_tail
decl_stmt|;
comment|/* name, i.e., rindex(fi_path, '/') + 1 */
specifier|const
name|char
modifier|*
name|fi_base
decl_stmt|;
comment|/* tail minus ".c" (or whatever) */
name|struct
name|nvlist
modifier|*
name|fi_opt
decl_stmt|;
comment|/* optional on ... */
specifier|const
name|char
modifier|*
name|fi_mkrule
decl_stmt|;
comment|/* special make rule, if any */
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|FI_SEL
value|0x01
end_define

begin_comment
comment|/* selected */
end_comment

begin_define
define|#
directive|define
name|FI_CONFIGDEP
value|0x02
end_define

begin_comment
comment|/* config-dependent */
end_comment

begin_define
define|#
directive|define
name|FI_DRIVER
value|0x04
end_define

begin_comment
comment|/* device-driver */
end_comment

begin_define
define|#
directive|define
name|FI_NEEDSCOUNT
value|0x08
end_define

begin_comment
comment|/* needs-count */
end_comment

begin_define
define|#
directive|define
name|FI_NEEDSFLAG
value|0x10
end_define

begin_comment
comment|/* needs-flag */
end_comment

begin_define
define|#
directive|define
name|FI_HIDDEN
value|0x20
end_define

begin_comment
comment|/* obscured by other(s), base names overlap */
end_comment

begin_comment
comment|/*  * Hash tables look up name=value pairs.  The pointer value of the name  * is assumed to be constant forever; this can be arranged by interning  * the name.  (This is fairly convenient since our lexer does this for  * all identifier-like strings---it has to save them anyway, lest yacc's  * look-ahead wipe out the current one.)  */
end_comment

begin_struct_decl
struct_decl|struct
name|hashtab
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|const
name|char
modifier|*
name|conffile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source file, e.g., "GENERIC.sparc" */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|confdirbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* basename of compile directory, usu. same */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|machine
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* machine type, e.g., "sparc" */
end_comment

begin_decl_stmt
name|int
name|errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts calls to error() */
end_comment

begin_decl_stmt
name|int
name|minmaxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum "maxusers" parameter */
end_comment

begin_decl_stmt
name|int
name|defmaxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default "maxusers" parameter */
end_comment

begin_decl_stmt
name|int
name|maxmaxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default "maxusers" parameter */
end_comment

begin_decl_stmt
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration's "maxusers" parameter */
end_comment

begin_decl_stmt
name|struct
name|nvlist
modifier|*
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options */
end_comment

begin_decl_stmt
name|struct
name|nvlist
modifier|*
name|mkoptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* makeoptions */
end_comment

begin_decl_stmt
name|struct
name|hashtab
modifier|*
name|devbasetab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* devbase lookup */
end_comment

begin_decl_stmt
name|struct
name|hashtab
modifier|*
name|selecttab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* selects things that are "optional foo" */
end_comment

begin_decl_stmt
name|struct
name|hashtab
modifier|*
name|needcnttab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* retains names marked "needs-count" */
end_comment

begin_decl_stmt
name|struct
name|devbase
modifier|*
name|allbases
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all devbase structures */
end_comment

begin_decl_stmt
name|struct
name|config
modifier|*
name|allcf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of configured kernels */
end_comment

begin_decl_stmt
name|struct
name|devi
modifier|*
name|alldevi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all instances */
end_comment

begin_decl_stmt
name|struct
name|devi
modifier|*
name|allpseudo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all pseudo-devices */
end_comment

begin_decl_stmt
name|int
name|ndevi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of devi's (before packing) */
end_comment

begin_decl_stmt
name|int
name|npseudo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of pseudo's */
end_comment

begin_decl_stmt
name|struct
name|files
modifier|*
name|allfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all kernel source files */
end_comment

begin_decl_stmt
name|struct
name|devi
modifier|*
modifier|*
name|packed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arrayified table for packed devi's */
end_comment

begin_decl_stmt
name|int
name|npacked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of packed table,<= ndevi */
end_comment

begin_struct
struct|struct
block|{
comment|/* pv[] table for config */
name|short
modifier|*
name|vec
decl_stmt|;
name|int
name|used
decl_stmt|;
block|}
name|parents
struct|;
end_struct

begin_struct
struct|struct
block|{
comment|/* loc[] table for config */
specifier|const
name|char
modifier|*
modifier|*
name|vec
decl_stmt|;
name|int
name|used
decl_stmt|;
block|}
name|locators
struct|;
end_struct

begin_comment
comment|/* files.c */
end_comment

begin_decl_stmt
name|void
name|initfiles
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|checkfiles
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fixfiles
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* finalize */
end_comment

begin_decl_stmt
name|void
name|addfile
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|nvlist
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash.c */
end_comment

begin_decl_stmt
name|struct
name|hashtab
modifier|*
name|ht_new
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ht_insrep
name|__P
argument_list|(
operator|(
expr|struct
name|hashtab
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ht_insert
parameter_list|(
name|ht
parameter_list|,
name|nam
parameter_list|,
name|val
parameter_list|)
value|ht_insrep(ht, nam, val, 0)
end_define

begin_define
define|#
directive|define
name|ht_replace
parameter_list|(
name|ht
parameter_list|,
name|nam
parameter_list|,
name|val
parameter_list|)
value|ht_insrep(ht, nam, val, 1)
end_define

begin_decl_stmt
name|void
modifier|*
name|ht_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|hashtab
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
name|void
name|initintern
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|intern
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
name|void
name|addoption
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addmkoption
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mkheaders.c */
end_comment

begin_decl_stmt
name|int
name|mkheaders
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mkioconf.c */
end_comment

begin_decl_stmt
name|int
name|mkioconf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mkmakefile.c */
end_comment

begin_decl_stmt
name|int
name|mkmakefile
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mkswap.c */
end_comment

begin_decl_stmt
name|int
name|mkswap
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pack.c */
end_comment

begin_decl_stmt
name|void
name|pack
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scan.l */
end_comment

begin_decl_stmt
name|int
name|currentline
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sem.c, other than for yacc actions */
end_comment

begin_decl_stmt
name|void
name|initsem
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
name|void
modifier|*
name|emalloc
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|erealloc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|path
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|error
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* immediate errs */
end_comment

begin_decl_stmt
name|void
name|xerror
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delayed errs */
end_comment

begin_decl_stmt
name|__dead
name|void
name|panic
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nvlist
modifier|*
name|newnv
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nvfree
name|__P
argument_list|(
operator|(
expr|struct
name|nvlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nvfreel
name|__P
argument_list|(
operator|(
expr|struct
name|nvlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

