begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: stab.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:20 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: stab.h,v $  * Revision 1.2  1995/05/30 05:03:20  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:39  nate  * PERL!  *  * Revision 4.0.1.3  92/06/08  15:33:44  lwall  * patch20: fixed confusion between a *var's real name and its effective name  * patch20: ($<,$>) = ... didn't work on some architectures  *  * Revision 4.0.1.2  91/11/05  18:36:15  lwall  * patch11: length($x) was sometimes wrong for numeric $x  *  * Revision 4.0.1.1  91/06/07  11:56:35  lwall  * patch4: new copyright notice  * patch4: length($`), length($&), length($') now optimized to avoid string copy  *  * Revision 4.0  91/03/20  01:39:49  lwall  * 4.0 baseline.  *  */
end_comment

begin_struct
struct|struct
name|stabptrs
block|{
name|char
name|stbp_magic
index|[
literal|4
index|]
decl_stmt|;
name|STR
modifier|*
name|stbp_val
decl_stmt|;
comment|/* scalar value */
name|struct
name|stio
modifier|*
name|stbp_io
decl_stmt|;
comment|/* filehandle value */
name|FCMD
modifier|*
name|stbp_form
decl_stmt|;
comment|/* format value */
name|ARRAY
modifier|*
name|stbp_array
decl_stmt|;
comment|/* array value */
name|HASH
modifier|*
name|stbp_hash
decl_stmt|;
comment|/* associative array value */
name|STAB
modifier|*
name|stbp_stab
decl_stmt|;
comment|/* effective stab, if *glob */
name|SUBR
modifier|*
name|stbp_sub
decl_stmt|;
comment|/* subroutine value */
name|int
name|stbp_lastexpr
decl_stmt|;
comment|/* used by nothing_in_common() */
name|line_t
name|stbp_line
decl_stmt|;
comment|/* line first declared at (for -w) */
name|char
name|stbp_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRIPPLED_CC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|iAPX286
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I286
argument_list|)
operator|||
name|defined
argument_list|(
name|I80286
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|MICROPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|stab_magic
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_magic)
end_define

begin_define
define|#
directive|define
name|stab_val
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_val)
end_define

begin_define
define|#
directive|define
name|stab_io
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_io)
end_define

begin_define
define|#
directive|define
name|stab_form
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_form)
end_define

begin_define
define|#
directive|define
name|stab_xarray
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_array)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MICROPORT
end_ifdef

begin_comment
comment|/* Microport 2.4 hack */
end_comment

begin_function_decl
name|ARRAY
modifier|*
name|stab_array
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stab_array
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_array ? \ 				 ((STBP*)(stab->str_ptr))->stbp_array : \ 				 ((STBP*)(aadd(stab)->str_ptr))->stbp_array)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|stab_xhash
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_hash)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MICROPORT
end_ifdef

begin_comment
comment|/* Microport 2.4 hack */
end_comment

begin_function_decl
name|HASH
modifier|*
name|stab_hash
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stab_hash
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_hash ? \ 				 ((STBP*)(stab->str_ptr))->stbp_hash : \ 				 ((STBP*)(hadd(stab)->str_ptr))->stbp_hash)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Microport 2.4 hack */
end_comment

begin_define
define|#
directive|define
name|stab_sub
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_sub)
end_define

begin_define
define|#
directive|define
name|stab_lastexpr
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_lastexpr)
end_define

begin_define
define|#
directive|define
name|stab_line
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_line)
end_define

begin_define
define|#
directive|define
name|stab_flags
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_flags)
end_define

begin_define
define|#
directive|define
name|stab_stab
parameter_list|(
name|stab
parameter_list|)
value|(stab->str_magic->str_u.str_stab)
end_define

begin_define
define|#
directive|define
name|stab_estab
parameter_list|(
name|stab
parameter_list|)
value|(((STBP*)(stab->str_ptr))->stbp_stab)
end_define

begin_define
define|#
directive|define
name|stab_name
parameter_list|(
name|stab
parameter_list|)
value|(stab->str_magic->str_ptr)
end_define

begin_define
define|#
directive|define
name|stab_ename
parameter_list|(
name|stab
parameter_list|)
value|stab_name(stab_estab(stab))
end_define

begin_define
define|#
directive|define
name|stab_stash
parameter_list|(
name|stab
parameter_list|)
value|(stab->str_magic->str_u.str_stash)
end_define

begin_define
define|#
directive|define
name|stab_estash
parameter_list|(
name|stab
parameter_list|)
value|stab_stash(stab_estab(stab))
end_define

begin_define
define|#
directive|define
name|SF_VMAGIC
value|1
end_define

begin_comment
comment|/* call routine to dereference STR val */
end_comment

begin_define
define|#
directive|define
name|SF_MULTI
value|2
end_define

begin_comment
comment|/* seen more than once */
end_comment

begin_struct
struct|struct
name|stio
block|{
name|FILE
modifier|*
name|ifp
decl_stmt|;
comment|/* ifp and ofp are normally the same */
name|FILE
modifier|*
name|ofp
decl_stmt|;
comment|/* but sockets need separate streams */
ifdef|#
directive|ifdef
name|HAS_READDIR
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* for opendir, readdir, etc */
endif|#
directive|endif
name|long
name|lines
decl_stmt|;
comment|/* $. */
name|long
name|page
decl_stmt|;
comment|/* $% */
name|long
name|page_len
decl_stmt|;
comment|/* $= */
name|long
name|lines_left
decl_stmt|;
comment|/* $- */
name|char
modifier|*
name|top_name
decl_stmt|;
comment|/* $^ */
name|STAB
modifier|*
name|top_stab
decl_stmt|;
comment|/* $^ */
name|char
modifier|*
name|fmt_name
decl_stmt|;
comment|/* $~ */
name|STAB
modifier|*
name|fmt_stab
decl_stmt|;
comment|/* $~ */
name|short
name|subprocess
decl_stmt|;
comment|/* -| or |- */
name|char
name|type
decl_stmt|;
name|char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOF_ARGV
value|1
end_define

begin_comment
comment|/* this fp iterates over ARGV */
end_comment

begin_define
define|#
directive|define
name|IOF_START
value|2
end_define

begin_comment
comment|/* check for null ARGV and substitute '-' */
end_comment

begin_define
define|#
directive|define
name|IOF_FLUSH
value|4
end_define

begin_comment
comment|/* this fp wants a flush after write op */
end_comment

begin_struct
struct|struct
name|sub
block|{
name|CMD
modifier|*
name|cmd
decl_stmt|;
name|int
function_decl|(
modifier|*
name|usersub
function_decl|)
parameter_list|()
function_decl|;
name|int
name|userindex
decl_stmt|;
name|STAB
modifier|*
name|filestab
decl_stmt|;
name|long
name|depth
decl_stmt|;
comment|/*>= 2 indicates recursive call */
name|ARRAY
modifier|*
name|tosave
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Nullstab
value|Null(STAB*)
end_define

begin_function_decl
name|STRLEN
name|stab_len
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STAB_STR
parameter_list|(
name|s
parameter_list|)
value|(tmpstab = (s), stab_flags(tmpstab)& SF_VMAGIC ? stab_str(stab_val(tmpstab)->str_magic) : stab_val(tmpstab))
end_define

begin_define
define|#
directive|define
name|STAB_LEN
parameter_list|(
name|s
parameter_list|)
value|(tmpstab = (s), stab_flags(tmpstab)& SF_VMAGIC ? stab_len(stab_val(tmpstab)->str_magic) : str_len(stab_val(tmpstab)))
end_define

begin_define
define|#
directive|define
name|STAB_GET
parameter_list|(
name|s
parameter_list|)
value|(tmpstab = (s), str_get(stab_flags(tmpstab)& SF_VMAGIC ? stab_str(tmpstab->str_magic) : stab_val(tmpstab)))
end_define

begin_define
define|#
directive|define
name|STAB_GNUM
parameter_list|(
name|s
parameter_list|)
value|(tmpstab = (s), str_gnum(stab_flags(tmpstab)& SF_VMAGIC ? stab_str(tmpstab->str_magic) : stab_val(tmpstab)))
end_define

begin_decl_stmt
name|EXT
name|STAB
modifier|*
name|tmpstab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|STAB
modifier|*
name|stab_index
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|unsigned
name|short
name|statusvalue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|delaymagic
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DM_UID
value|0x003
end_define

begin_define
define|#
directive|define
name|DM_RUID
value|0x001
end_define

begin_define
define|#
directive|define
name|DM_EUID
value|0x002
end_define

begin_define
define|#
directive|define
name|DM_GID
value|0x030
end_define

begin_define
define|#
directive|define
name|DM_RGID
value|0x010
end_define

begin_define
define|#
directive|define
name|DM_EGID
value|0x020
end_define

begin_define
define|#
directive|define
name|DM_DELAY
value|0x100
end_define

begin_function_decl
name|STAB
modifier|*
name|aadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STAB
modifier|*
name|hadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STAB
modifier|*
name|fstab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stabset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stab_fullname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stab_efullname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stab_check
parameter_list|()
function_decl|;
end_function_decl

end_unit

