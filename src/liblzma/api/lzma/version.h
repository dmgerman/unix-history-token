begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/version.h  * \brief       Version number  */
end_comment

begin_comment
comment|/*  * Author: Lasse Collin  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  *  * See ../lzma.h for information about liblzma as a whole.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_H_INTERNAL
end_ifndef

begin_error
error|#
directive|error
error|Never include this file directly. Use<lzma.h> instead.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Version number split into components  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VERSION_MAJOR
value|5
end_define

begin_define
define|#
directive|define
name|LZMA_VERSION_MINOR
value|0
end_define

begin_define
define|#
directive|define
name|LZMA_VERSION_PATCH
value|7
end_define

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY
value|LZMA_VERSION_STABILITY_STABLE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_VERSION_COMMIT
end_ifndef

begin_define
define|#
directive|define
name|LZMA_VERSION_COMMIT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Map symbolic stability levels to integers.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY_ALPHA
value|0
end_define

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY_BETA
value|1
end_define

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY_STABLE
value|2
end_define

begin_comment
comment|/**  * \brief       Compile-time version number  *  * The version number is of format xyyyzzzs where  *  - x = major  *  - yyy = minor  *  - zzz = revision  *  - s indicates stability: 0 = alpha, 1 = beta, 2 = stable  *  * The same xyyyzzz triplet is never reused with different stability levels.  * For example, if 5.1.0alpha has been released, there will never be 5.1.0beta  * or 5.1.0 stable.  *  * \note        The version number of liblzma has nothing to with  *              the version number of Igor Pavlov's LZMA SDK.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VERSION
value|(LZMA_VERSION_MAJOR * UINT32_C(10000000) \ 		+ LZMA_VERSION_MINOR * UINT32_C(10000) \ 		+ LZMA_VERSION_PATCH * UINT32_C(10) \ 		+ LZMA_VERSION_STABILITY)
end_define

begin_comment
comment|/*  * Macros to construct the compile-time version string  */
end_comment

begin_if
if|#
directive|if
name|LZMA_VERSION_STABILITY
operator|==
name|LZMA_VERSION_STABILITY_ALPHA
end_if

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY_STRING
value|"alpha"
end_define

begin_elif
elif|#
directive|elif
name|LZMA_VERSION_STABILITY
operator|==
name|LZMA_VERSION_STABILITY_BETA
end_elif

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY_STRING
value|"beta"
end_define

begin_elif
elif|#
directive|elif
name|LZMA_VERSION_STABILITY
operator|==
name|LZMA_VERSION_STABILITY_STABLE
end_elif

begin_define
define|#
directive|define
name|LZMA_VERSION_STABILITY_STRING
value|""
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Incorrect LZMA_VERSION_STABILITY
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LZMA_VERSION_STRING_C_
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|patch
parameter_list|,
name|stability
parameter_list|,
name|commit
parameter_list|)
define|\
value|#major "." #minor "." #patch stability commit
end_define

begin_define
define|#
directive|define
name|LZMA_VERSION_STRING_C
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|patch
parameter_list|,
name|stability
parameter_list|,
name|commit
parameter_list|)
define|\
value|LZMA_VERSION_STRING_C_(major, minor, patch, stability, commit)
end_define

begin_comment
comment|/**  * \brief       Compile-time version as a string  *  * This can be for example "4.999.5alpha", "4.999.8beta", or "5.0.0" (stable  * versions don't have any "stable" suffix). In future, a snapshot built  * from source code repository may include an additional suffix, for example  * "4.999.8beta-21-g1d92". The commit ID won't be available in numeric form  * in LZMA_VERSION macro.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VERSION_STRING
value|LZMA_VERSION_STRING_C( \ 		LZMA_VERSION_MAJOR, LZMA_VERSION_MINOR, \ 		LZMA_VERSION_PATCH, LZMA_VERSION_STABILITY_STRING, \ 		LZMA_VERSION_COMMIT)
end_define

begin_comment
comment|/* #ifndef is needed for use with windres (MinGW or Cygwin). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_H_INTERNAL_RC
end_ifndef

begin_comment
comment|/**  * \brief       Run-time version number as an integer  *  * Return the value of LZMA_VERSION macro at the compile time of liblzma.  * This allows the application to compare if it was built against the same,  * older, or newer version of liblzma that is currently running.  */
end_comment

begin_extern
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_version_number
argument_list|(
argument|void
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Run-time version as a string  *  * This function may be useful if you want to display which version of  * liblzma your application is currently using.  */
end_comment

begin_extern
extern|extern LZMA_API(const char *
end_extern

begin_macro
unit|)
name|lzma_version_string
argument_list|(
argument|void
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

