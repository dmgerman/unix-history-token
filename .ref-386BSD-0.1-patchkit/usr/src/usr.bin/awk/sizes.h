begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** sizes.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	sizes.h,v $  * Revision 5.1  91/12/05  07:59:35  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/*  sizes.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZES_H
end_ifndef

begin_define
define|#
directive|define
name|SIZES_H
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_SMALL_MEMORY
end_if

begin_define
define|#
directive|define
name|EVAL_STACK_SIZE
value|256
end_define

begin_comment
comment|/* limit on recursion */
end_comment

begin_comment
comment|/* number of fields at startup, must be a power of 2     and FBANK_SZ-1 must be divisible by 3! */
end_comment

begin_define
define|#
directive|define
name|FBANK_SZ
value|256
end_define

begin_define
define|#
directive|define
name|FB_SHIFT
value|8
end_define

begin_comment
comment|/* lg(FBANK_SZ) */
end_comment

begin_define
define|#
directive|define
name|NUM_FBANK
value|128
end_define

begin_comment
comment|/* see MAX_FIELD below */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* have to be frugal with memory */
end_comment

begin_define
define|#
directive|define
name|EVAL_STACK_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FBANK_SZ
value|64
end_define

begin_define
define|#
directive|define
name|FB_SHIFT
value|6
end_define

begin_comment
comment|/* lg(FBANK_SZ) */
end_comment

begin_define
define|#
directive|define
name|NUM_FBANK
value|16
end_define

begin_comment
comment|/* see MAX_FIELD below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_SPLIT
value|(FBANK_SZ-1)
end_define

begin_comment
comment|/* needs to be divisble by 3*/
end_comment

begin_define
define|#
directive|define
name|MAX_FIELD
value|(NUM_FBANK*FBANK_SZ - 1)
end_define

begin_define
define|#
directive|define
name|MIN_SPRINTF
value|400
end_define

begin_define
define|#
directive|define
name|BUFFSZ
value|4096
end_define

begin_comment
comment|/* starting buffer size for input files, grows if       necessary */
end_comment

begin_define
define|#
directive|define
name|HASH_PRIME
value|53
end_define

begin_define
define|#
directive|define
name|A_HASH_PRIME
value|37
end_define

begin_define
define|#
directive|define
name|MAX_COMPILE_ERRORS
value|5
end_define

begin_comment
comment|/* quit if more than 4 errors */
end_comment

begin_comment
comment|/* AWF showed the need for this */
end_comment

begin_define
define|#
directive|define
name|MAIN_PAGE_SZ
value|4096
end_define

begin_comment
comment|/* max instr in main block */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PAGE_SZ
value|1024
end_define

begin_comment
comment|/* max instructions for other blocks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* these used to be different */
end_comment

begin_define
define|#
directive|define
name|PAGE_SZ
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIZES_H */
end_comment

end_unit

