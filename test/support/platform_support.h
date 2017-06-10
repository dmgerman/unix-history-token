begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Define a bunch of macros that can be used in the tests instead of
end_comment

begin_comment
comment|//  implementation defined assumptions:
end_comment

begin_comment
comment|//   - locale names
end_comment

begin_comment
comment|//   - floating point number string output
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PLATFORM_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|PLATFORM_SUPPORT_H
end_define

begin_comment
comment|// locale names
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_comment
comment|// WARNING: Windows does not support UTF-8 codepages.
end_comment

begin_comment
comment|// Locales are "converted" using http://docs.moodle.org/dev/Table_of_locales
end_comment

begin_define
define|#
directive|define
name|LOCALE_en_US
value|"en-US"
end_define

begin_define
define|#
directive|define
name|LOCALE_en_US_UTF_8
value|"en-US"
end_define

begin_define
define|#
directive|define
name|LOCALE_cs_CZ_ISO8859_2
value|"cs-CZ"
end_define

begin_define
define|#
directive|define
name|LOCALE_fr_FR_UTF_8
value|"fr-FR"
end_define

begin_define
define|#
directive|define
name|LOCALE_fr_CA_ISO8859_1
value|"fr-CA"
end_define

begin_define
define|#
directive|define
name|LOCALE_ru_RU_UTF_8
value|"ru-RU"
end_define

begin_define
define|#
directive|define
name|LOCALE_zh_CN_UTF_8
value|"zh-CN"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__CloudABI__
argument_list|)
end_elif

begin_comment
comment|// Timezones are integrated into locales through LC_TIMEZONE_MASK on
end_comment

begin_comment
comment|// CloudABI. LC_ALL_MASK can only be used if a timezone has also been
end_comment

begin_comment
comment|// provided. UTC should be all right.
end_comment

begin_define
define|#
directive|define
name|LOCALE_en_US
value|"en_US"
end_define

begin_define
define|#
directive|define
name|LOCALE_en_US_UTF_8
value|"en_US.UTF-8@UTC"
end_define

begin_define
define|#
directive|define
name|LOCALE_fr_FR_UTF_8
value|"fr_FR.UTF-8@UTC"
end_define

begin_define
define|#
directive|define
name|LOCALE_fr_CA_ISO8859_1
value|"fr_CA.ISO-8859-1@UTC"
end_define

begin_define
define|#
directive|define
name|LOCALE_cs_CZ_ISO8859_2
value|"cs_CZ.ISO-8859-2@UTC"
end_define

begin_define
define|#
directive|define
name|LOCALE_ru_RU_UTF_8
value|"ru_RU.UTF-8@UTC"
end_define

begin_define
define|#
directive|define
name|LOCALE_zh_CN_UTF_8
value|"zh_CN.UTF-8@UTC"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCALE_en_US
value|"en_US"
end_define

begin_define
define|#
directive|define
name|LOCALE_en_US_UTF_8
value|"en_US.UTF-8"
end_define

begin_define
define|#
directive|define
name|LOCALE_fr_FR_UTF_8
value|"fr_FR.UTF-8"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|LOCALE_fr_CA_ISO8859_1
value|"fr_CA.ISO-8859-1"
end_define

begin_define
define|#
directive|define
name|LOCALE_cs_CZ_ISO8859_2
value|"cs_CZ.ISO-8859-2"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCALE_fr_CA_ISO8859_1
value|"fr_CA.ISO8859-1"
end_define

begin_define
define|#
directive|define
name|LOCALE_cs_CZ_ISO8859_2
value|"cs_CZ.ISO8859-2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOCALE_ru_RU_UTF_8
value|"ru_RU.UTF-8"
end_define

begin_define
define|#
directive|define
name|LOCALE_zh_CN_UTF_8
value|"zh_CN.UTF-8"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_comment
comment|// _mktemp_s
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|// close
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NEWLIB_VERSION
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_comment
comment|// Newlib provides this, but in the header it's under __STRICT_ANSI__
end_comment

begin_extern
extern|extern
literal|"C"
block|{
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__CloudABI__
end_ifndef

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
name|get_temp_file_name
argument_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
name|char
name|Path
index|[
name|MAX_PATH
operator|+
literal|1
index|]
block|;
name|char
name|FN
index|[
name|MAX_PATH
operator|+
literal|1
index|]
block|;
do|do
block|{
block|}
end_expr_stmt

begin_while
while|while
condition|(
literal|0
operator|==
name|GetTempPath
argument_list|(
name|MAX_PATH
operator|+
literal|1
argument_list|,
name|Path
argument_list|)
condition|)
empty_stmt|;
end_while

begin_do
do|do
block|{ }
do|while
condition|(
literal|0
operator|==
name|GetTempFileName
argument_list|(
name|Path
argument_list|,
literal|"libcxx"
argument_list|,
literal|0
argument_list|,
name|FN
argument_list|)
condition|)
do|;
end_do

begin_return
return|return
name|FN
return|;
end_return

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_decl_stmt
name|char
name|Name
index|[]
init|=
literal|"libcxx.XXXXXX"
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|_mktemp_s
argument_list|(
name|Name
argument_list|,
sizeof|sizeof
argument_list|(
name|Name
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|Name
return|;
end_return

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|std
operator|::
name|string
name|Name
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|FD
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_do
do|do
block|{
name|Name
operator|=
literal|"libcxx.XXXXXX"
expr_stmt|;
name|FD
operator|=
name|mkstemp
argument_list|(
operator|&
name|Name
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|FD
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINVAL
condition|)
block|{
name|perror
argument_list|(
literal|"mkstemp"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
do|while
condition|(
name|FD
operator|==
operator|-
literal|1
condition|)
do|;
end_do

begin_expr_stmt
name|close
argument_list|(
name|FD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Name
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// __CloudABI__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PLATFORM_SUPPORT_H
end_comment

end_unit

