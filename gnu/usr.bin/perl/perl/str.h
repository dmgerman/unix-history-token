begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: str.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:22 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: str.h,v $  * Revision 1.2  1995/05/30 05:03:22  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:39  nate  * PERL!  *  * Revision 4.0.1.4  92/06/08  15:41:45  lwall  * patch20: fixed confusion between a *var's real name and its effective name  * patch20: removed implicit int declarations on functions  *  * Revision 4.0.1.3  91/11/05  18:41:47  lwall  * patch11: random cleanup  * patch11: solitary subroutine references no longer trigger typo warnings  *  * Revision 4.0.1.2  91/06/07  11:58:33  lwall  * patch4: new copyright notice  *  * Revision 4.0.1.1  91/04/12  09:16:12  lwall  * patch1: you may now use "die" and "caller" in a signal handler  *  * Revision 4.0  91/03/20  01:40:04  lwall  * 4.0 baseline.  *  */
end_comment

begin_struct
struct|struct
name|string
block|{
name|char
modifier|*
name|str_ptr
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|str_len
decl_stmt|;
comment|/* allocated size */
union|union
block|{
name|double
name|str_nval
decl_stmt|;
comment|/* numeric value, if any */
name|long
name|str_useful
decl_stmt|;
comment|/* is this search optimization effective? */
name|ARG
modifier|*
name|str_args
decl_stmt|;
comment|/* list of args for interpreted string */
name|HASH
modifier|*
name|str_hash
decl_stmt|;
comment|/* string represents an assoc array (stab?) */
name|ARRAY
modifier|*
name|str_array
decl_stmt|;
comment|/* string represents an array */
name|CMD
modifier|*
name|str_cmd
decl_stmt|;
comment|/* command for this source line */
struct|struct
block|{
name|STAB
modifier|*
name|stb_stab
decl_stmt|;
comment|/* magic stab for magic "key" string */
name|HASH
modifier|*
name|stb_stash
decl_stmt|;
comment|/* which symbol table this stab is in */
block|}
name|stb_u
struct|;
block|}
name|str_u
union|;
name|STRLEN
name|str_cur
decl_stmt|;
comment|/* length of str_ptr as a C string */
name|STR
modifier|*
name|str_magic
decl_stmt|;
comment|/* while free, link to next free str */
comment|/* while in use, ptr to "key" for magic items */
name|unsigned
name|char
name|str_pok
decl_stmt|;
comment|/* state of str_ptr */
name|unsigned
name|char
name|str_nok
decl_stmt|;
comment|/* state of str_nval */
name|unsigned
name|char
name|str_rare
decl_stmt|;
comment|/* used by search strings */
name|unsigned
name|char
name|str_state
decl_stmt|;
comment|/* one of SS_* below */
comment|/* also used by search strings for backoff */
ifdef|#
directive|ifdef
name|TAINT
name|bool
name|str_tainted
decl_stmt|;
comment|/* 1 if possibly under control of $< */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|stab
block|{
comment|/* should be identical, except for str_ptr */
name|STBP
modifier|*
name|str_ptr
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|str_len
decl_stmt|;
comment|/* allocated size */
union|union
block|{
name|double
name|str_nval
decl_stmt|;
comment|/* numeric value, if any */
name|long
name|str_useful
decl_stmt|;
comment|/* is this search optimization effective? */
name|ARG
modifier|*
name|str_args
decl_stmt|;
comment|/* list of args for interpreted string */
name|HASH
modifier|*
name|str_hash
decl_stmt|;
comment|/* string represents an assoc array (stab?) */
name|ARRAY
modifier|*
name|str_array
decl_stmt|;
comment|/* string represents an array */
name|CMD
modifier|*
name|str_cmd
decl_stmt|;
comment|/* command for this source line */
struct|struct
block|{
name|STAB
modifier|*
name|stb_stab
decl_stmt|;
comment|/* magic stab for magic "key" string */
name|HASH
modifier|*
name|stb_stash
decl_stmt|;
comment|/* which symbol table this stab is in */
block|}
name|stb_u
struct|;
block|}
name|str_u
union|;
name|STRLEN
name|str_cur
decl_stmt|;
comment|/* length of str_ptr as a C string */
name|STR
modifier|*
name|str_magic
decl_stmt|;
comment|/* while free, link to next free str */
comment|/* while in use, ptr to "key" for magic items */
name|unsigned
name|char
name|str_pok
decl_stmt|;
comment|/* state of str_ptr */
name|unsigned
name|char
name|str_nok
decl_stmt|;
comment|/* state of str_nval */
name|unsigned
name|char
name|str_rare
decl_stmt|;
comment|/* used by search strings */
name|unsigned
name|char
name|str_state
decl_stmt|;
comment|/* one of SS_* below */
comment|/* also used by search strings for backoff */
ifdef|#
directive|ifdef
name|TAINT
name|bool
name|str_tainted
decl_stmt|;
comment|/* 1 if possibly under control of $< */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|str_stab
value|stb_u.stb_stab
end_define

begin_define
define|#
directive|define
name|str_stash
value|stb_u.stb_stash
end_define

begin_comment
comment|/* some extra info tacked to some lvalue strings */
end_comment

begin_struct
struct|struct
name|lstring
block|{
name|struct
name|string
name|lstr
decl_stmt|;
name|STRLEN
name|lstr_offset
decl_stmt|;
name|STRLEN
name|lstr_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These are the values of str_pok:		*/
end_comment

begin_define
define|#
directive|define
name|SP_VALID
value|1
end_define

begin_comment
comment|/* str_ptr is valid */
end_comment

begin_define
define|#
directive|define
name|SP_FBM
value|2
end_define

begin_comment
comment|/* string was compiled for fbm search */
end_comment

begin_define
define|#
directive|define
name|SP_STUDIED
value|4
end_define

begin_comment
comment|/* string was studied */
end_comment

begin_define
define|#
directive|define
name|SP_CASEFOLD
value|8
end_define

begin_comment
comment|/* case insensitive fbm search */
end_comment

begin_define
define|#
directive|define
name|SP_INTRP
value|16
end_define

begin_comment
comment|/* string was compiled for interping */
end_comment

begin_define
define|#
directive|define
name|SP_TAIL
value|32
end_define

begin_comment
comment|/* fbm string is tail anchored: /foo$/  */
end_comment

begin_define
define|#
directive|define
name|SP_MULTI
value|64
end_define

begin_comment
comment|/* symbol table entry probably isn't a typo */
end_comment

begin_define
define|#
directive|define
name|SP_TEMP
value|128
end_define

begin_comment
comment|/* string slated to die, so can be plundered */
end_comment

begin_define
define|#
directive|define
name|Nullstr
value|Null(STR*)
end_define

begin_comment
comment|/* These are the values of str_state:		*/
end_comment

begin_define
define|#
directive|define
name|SS_NORM
value|0
end_define

begin_comment
comment|/* normal string */
end_comment

begin_define
define|#
directive|define
name|SS_INCR
value|1
end_define

begin_comment
comment|/* normal string, incremented ptr */
end_comment

begin_define
define|#
directive|define
name|SS_SARY
value|2
end_define

begin_comment
comment|/* array on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SHASH
value|3
end_define

begin_comment
comment|/* associative array on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SINT
value|4
end_define

begin_comment
comment|/* integer on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SLONG
value|5
end_define

begin_comment
comment|/* long on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SSTRP
value|6
end_define

begin_comment
comment|/* STR* on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SHPTR
value|7
end_define

begin_comment
comment|/* HASH* on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SNSTAB
value|8
end_define

begin_comment
comment|/* non-stab on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SCSV
value|9
end_define

begin_comment
comment|/* callsave structure on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_SAPTR
value|10
end_define

begin_comment
comment|/* ARRAY* on save stack */
end_comment

begin_define
define|#
directive|define
name|SS_HASH
value|253
end_define

begin_comment
comment|/* carrying an hash */
end_comment

begin_define
define|#
directive|define
name|SS_ARY
value|254
end_define

begin_comment
comment|/* carrying an array */
end_comment

begin_define
define|#
directive|define
name|SS_FREE
value|255
end_define

begin_comment
comment|/* in free list */
end_comment

begin_comment
comment|/* str_state may have any value 0-255 when used to hold fbm pattern, in which */
end_comment

begin_comment
comment|/* case it indicates offset to rarest character in screaminstr key */
end_comment

begin_comment
comment|/* the following macro updates any magic values this str is associated with */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TAINT
end_ifdef

begin_define
define|#
directive|define
name|STABSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->str_tainted |= tainted; \     if ((x)->str_magic) \ 	stabset((x)->str_magic,(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STABSET
parameter_list|(
name|x
parameter_list|)
define|\
value|if ((x)->str_magic) \ 	stabset((x)->str_magic,(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STR_SSET
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|if (dst != src) str_sset(dst,src)
end_define

begin_decl_stmt
name|EXT
name|STR
modifier|*
modifier|*
name|tmps_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|tmps_max
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|tmps_base
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|str_2ptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|str_2num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_mortal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_2mortal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_make
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_nmake
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_smake
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_cmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_eq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_magic
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_numset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_sset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_nset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_chop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_scat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_ncat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_reset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_taintproper
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_taintenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRLEN
name|str_len
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MULTI
value|(3)
end_define

end_unit

