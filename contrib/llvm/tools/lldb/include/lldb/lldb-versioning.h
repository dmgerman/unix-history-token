begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-versioning.h ----------------------------------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_lldb_versioning_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_versioning_h_
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// LLDB API version
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_API_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION
value|0
end_define

begin_comment
comment|/*   API versioning  ---------------------------------    The LLDB API is versioned independently of the LLDB source base  Our API version numbers are composed of a major and a minor number   The major number means a complete and stable revision of the API. Major numbers are compatibility breakers  (i.e. when we change the API major number, there is no promise of compatibility with the previous major version   and we are free to remove and/or change any APIs)  Minor numbers are a work-in-progress evolution of the API. APIs will not be removed or changed across minor versions  (minors do not break compatibility). However, we can deprecate APIs in minor versions or add new APIs in minor versions  A deprecated API is supposedly going to be removed in the next major version and will generate a warning if used  APIs we add in minor versions will not be removed (at least until the following major) but they might theoretically be deprecated  in a following minor version  Users are discouraged from using the LLDB version number to test for API features and should instead use the API version checking  as discussed below     API version checking  ---------------------------------    You can (optionally) sign into an API version checking feature  To do so you need to define three macros:  LLDB_API_CHECK_VERSIONING - define to any value (or no value)  LLDB_API_MAJOR_VERSION_WANTED - which major version of the LLDB API you are targeting  LLDB_API_MINOR_VERSION_WANTED - which minor version of the LLDB API you are targeting    If these macros exist - LLDB will enable version checking of the public API    If LLDB_API_MAJOR_VERSION is not equal to LLDB_API_MAJOR_VERSION_WANTED we will immediately halt your compilation with an error  This is by design, since we do not make any promise of compatibility across major versions - if you really want to test your luck, disable the versioning altogether    If the major version test passes, you have signed up for a specific minor version of the API  Whenever we add or deprecate an API in a minor version, we will mark it with either  LLDB_API_NEW_IN_DOT_x - this API is new in LLDB .x  LLDB_API_DEPRECATED_IN_DOT_x - this API is deprecated as of .x    If you are using an API new in DOT_x   if LLDB_API_MINOR_VERSION_WANTED>= x then all is well, else you will get a compilation error    This is meant to prevent you from using APIs that are newer than whatever LLDB you want to target   If you are using an API deprecated in DOT_x   if LLDB_API_MINOR_VERSION_WANTED>= x then you will get a compilation warning, else all is well   This is meant to let you know that you are using an API that is deprecated and might go away     Caveats  ---------------------------------    Version checking only works on clang on OSX - you will get an error if you try to enable it on any other OS/compiler  If you want to enable version checking on other platforms, you will need to define appropriate implementations for  LLDB_API_IMPL_DEPRECATED and LLDB_API_IMPL_TOONEW and any other infrastructure your compiler needs for this purpose    We have no deprecation-as-error mode    There is no support for API versioning in Python    We reserve to use macros whose names begin with LLDB_API_ and you should not use them in your source code as they might conflict  with present or future macro names we are using to implement versioning */
end_comment

begin_comment
comment|// if you want the version checking to work on other OS/compiler, define appropriate IMPL_DEPRECATED/IMPL_TOONEW
end_comment

begin_comment
comment|// and define LLDB_API_CHECK_VERSIONING_WORKS when you are ready to go live
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLDB_API_IMPL_DEPRECATED
value|__attribute__((deprecated))
end_define

begin_define
define|#
directive|define
name|LLDB_API_IMPL_TOONEW
value|__attribute__((unavailable))
end_define

begin_define
define|#
directive|define
name|LLDB_API_CHECK_VERSIONING_WORKS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLDB_API_CHECK_VERSIONING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LLDB_API_CHECK_VERSIONING_WORKS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"API version checking will not work here - please disable or create and submit patches to lldb-versioning.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLDB_API_CHECK_VERSIONING_WORKS
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|LLDB_API_IMPL_DEPRECATED
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|LLDB_API_IMPL_TOONEW
argument_list|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"LLDB_API_CHECK_VERSIONING_WORKS needs LLDB_API_IMPL_DEPRECATED and LLDB_API_IMPL_TOONEW to be defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLDB_API_CHECK_VERSIONING
argument_list|)
operator|&&
name|defined
argument_list|(
name|LLDB_API_MAJOR_VERSION_WANTED
argument_list|)
operator|&&
name|defined
argument_list|(
name|LLDB_API_MINOR_VERSION_WANTED
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLDB_API_MAJOR_VERSION
argument_list|)
operator|&&
operator|(
name|LLDB_API_MAJOR_VERSION
operator|!=
name|LLDB_API_MAJOR_VERSION_WANTED
operator|)
end_if

begin_error
error|#
directive|error
literal|"Cannot link using this LLDB version - public API versions are incompatible"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_0
value|0
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_1
value|1
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_2
value|2
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_3
value|3
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_4
value|4
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_5
value|5
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_6
value|6
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_7
value|7
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_8
value|8
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_9
value|9
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_10
value|10
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_11
value|11
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_12
value|12
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_13
value|13
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_14
value|14
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_15
value|15
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_16
value|16
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_17
value|17
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_18
value|18
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_19
value|19
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_20
value|20
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_21
value|21
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_22
value|22
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_23
value|23
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_24
value|24
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_25
value|25
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_26
value|26
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_27
value|27
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_28
value|28
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_29
value|29
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_30
value|30
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_31
value|31
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_32
value|32
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_33
value|33
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_34
value|34
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_35
value|35
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_36
value|36
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_37
value|37
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_38
value|38
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_39
value|39
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_40
value|40
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_41
value|41
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_42
value|42
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_43
value|43
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_44
value|44
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_45
value|45
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_46
value|46
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_47
value|47
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_48
value|48
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_49
value|49
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_50
value|50
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_51
value|51
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_52
value|52
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_53
value|53
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_54
value|54
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_55
value|55
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_56
value|56
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_57
value|57
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_58
value|58
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_59
value|59
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_60
value|60
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_61
value|61
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_62
value|62
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_63
value|63
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_64
value|64
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_65
value|65
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_66
value|66
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_67
value|67
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_68
value|68
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_69
value|69
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_70
value|70
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_71
value|71
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_72
value|72
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_73
value|73
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_74
value|74
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_75
value|75
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_76
value|76
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_77
value|77
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_78
value|78
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_79
value|79
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_80
value|80
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_81
value|81
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_82
value|82
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_83
value|83
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_84
value|84
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_85
value|85
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_86
value|86
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_87
value|87
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_88
value|88
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_89
value|89
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_90
value|90
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_91
value|91
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_92
value|92
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_93
value|93
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_94
value|94
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_95
value|95
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_96
value|96
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_97
value|97
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_98
value|98
end_define

begin_define
define|#
directive|define
name|LLDB_API_MINOR_VERSION_DOT_99
value|99
end_define

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_0
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_0
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_0
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_0
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_1
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_1
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_1
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_1
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_2
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_2
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_2
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_2
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_3
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_3
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_3
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_3
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_4
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_4
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_4
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_4
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_5
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_5
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_5
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_5
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_6
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_6
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_6
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_6
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_7
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_7
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_7
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_7
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_8
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_8
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_8
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_8
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_9
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_9
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_9
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_9
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_10
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_10
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_10
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_10
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_11
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_11
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_11
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_11
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_12
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_12
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_12
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_12
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_13
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_13
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_13
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_13
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_14
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_14
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_14
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_14
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_15
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_15
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_15
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_15
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_16
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_16
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_16
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_16
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_17
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_17
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_17
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_17
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_18
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_18
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_18
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_18
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_19
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_19
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_19
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_19
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_20
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_20
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_20
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_20
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_21
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_21
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_21
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_21
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_22
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_22
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_22
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_22
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_23
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_23
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_23
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_23
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_24
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_24
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_24
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_24
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_25
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_25
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_25
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_25
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_26
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_26
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_26
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_26
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_26
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_26
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_27
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_27
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_27
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_27
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_28
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_28
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_28
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_28
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_29
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_29
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_29
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_29
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_29
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_29
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_30
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_30
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_30
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_30
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_31
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_31
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_31
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_31
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_32
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_32
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_32
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_32
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_33
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_33
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_33
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_33
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_33
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_33
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_34
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_34
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_34
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_34
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_35
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_35
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_35
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_35
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_36
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_36
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_36
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_36
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_37
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_37
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_37
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_37
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_37
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_37
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_38
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_38
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_38
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_38
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_38
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_38
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_39
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_39
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_39
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_39
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_40
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_40
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_40
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_40
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_41
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_41
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_41
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_41
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_42
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_42
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_42
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_42
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_43
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_43
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_43
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_43
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_44
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_44
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_44
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_44
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_44
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_44
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_45
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_45
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_45
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_45
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_45
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_45
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_46
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_46
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_46
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_46
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_47
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_47
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_47
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_47
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_47
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_47
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_48
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_48
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_48
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_48
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_48
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_48
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_49
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_49
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_49
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_49
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_49
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_49
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_50
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_50
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_50
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_50
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_51
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_51
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_51
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_51
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_51
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_51
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_52
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_52
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_52
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_52
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_52
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_52
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_53
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_53
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_53
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_53
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_53
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_53
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_54
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_54
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_54
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_54
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_54
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_54
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_55
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_55
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_55
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_55
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_55
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_55
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_56
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_56
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_56
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_56
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_56
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_56
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_57
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_57
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_57
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_57
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_57
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_57
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_58
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_58
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_58
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_58
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_58
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_58
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_59
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_59
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_59
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_59
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_59
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_59
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_60
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_60
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_60
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_60
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_61
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_61
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_61
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_61
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_61
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_61
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_62
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_62
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_62
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_62
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_62
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_62
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_63
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_63
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_63
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_63
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_63
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_63
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_64
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_64
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_64
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_64
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_65
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_65
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_65
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_65
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_65
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_65
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_66
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_66
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_66
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_66
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_66
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_66
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_67
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_67
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_67
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_67
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_67
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_67
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_68
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_68
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_68
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_68
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_69
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_69
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_69
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_69
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_69
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_69
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_70
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_70
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_70
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_70
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_70
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_70
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_71
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_71
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_71
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_71
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_71
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_71
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_72
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_72
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_72
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_72
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_72
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_72
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_73
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_73
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_73
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_73
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_73
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_73
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_74
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_74
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_74
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_74
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_74
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_74
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_75
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_75
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_75
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_75
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_75
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_75
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_76
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_76
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_76
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_76
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_76
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_76
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_77
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_77
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_77
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_77
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_77
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_77
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_78
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_78
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_78
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_78
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_78
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_78
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_79
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_79
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_79
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_79
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_79
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_79
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_80
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_80
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_80
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_80
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_81
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_81
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_81
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_81
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_81
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_81
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_82
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_82
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_82
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_82
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_82
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_82
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_83
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_83
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_83
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_83
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_83
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_83
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_84
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_84
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_84
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_84
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_84
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_84
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_85
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_85
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_85
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_85
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_85
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_85
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_86
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_86
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_86
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_86
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_86
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_86
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_87
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_87
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_87
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_87
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_87
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_87
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_88
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_88
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_88
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_88
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_88
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_88
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_89
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_89
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_89
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_89
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_89
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_89
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_90
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_90
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_90
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_90
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_90
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_90
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_91
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_91
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_91
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_91
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_91
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_91
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_92
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_92
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_92
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_92
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_92
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_92
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_93
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_93
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_93
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_93
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_93
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_93
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_94
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_94
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_94
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_94
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_94
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_94
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_95
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_95
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_95
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_95
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_95
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_95
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_96
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_96
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_96
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_96
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_96
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_96
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_97
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_97
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_97
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_97
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_97
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_97
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_98
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_98
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_98
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_98
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_98
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_98
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|<
name|LLDB_API_MINOR_VERSION_DOT_99
end_if

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_99
value|LLDB_API_IMPL_TOONEW
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLDB_API_MINOR_VERSION_WANTED
operator|>=
name|LLDB_API_MINOR_VERSION_DOT_99
end_if

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_99
value|LLDB_API_IMPL_DEPRECATED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|// defined(LLDB_CHECK_API_VERSIONING)&& defined(LLDB_API_MAJOR_VERSION_WANTED)&& defined(LLDB_API_MINOR_VERSION_WANTED)&& defined (LLDB_API_MAJOR_VERSION)
end_comment

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_0
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_0
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_1
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_1
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_2
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_2
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_3
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_3
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_4
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_4
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_5
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_5
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_6
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_6
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_7
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_7
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_8
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_8
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_9
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_9
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_10
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_10
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_11
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_11
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_12
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_12
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_13
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_13
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_14
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_14
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_15
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_15
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_16
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_16
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_17
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_17
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_18
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_18
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_19
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_19
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_20
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_20
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_21
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_21
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_22
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_22
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_23
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_23
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_24
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_24
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_25
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_25
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_26
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_26
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_27
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_27
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_28
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_28
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_29
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_29
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_30
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_30
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_31
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_31
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_32
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_32
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_33
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_33
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_34
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_34
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_35
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_35
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_36
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_36
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_37
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_37
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_38
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_38
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_39
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_39
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_40
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_40
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_41
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_41
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_42
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_42
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_43
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_43
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_44
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_44
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_45
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_45
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_46
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_46
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_47
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_47
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_48
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_48
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_49
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_49
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_50
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_50
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_51
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_51
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_52
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_52
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_53
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_53
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_54
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_54
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_55
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_55
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_56
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_56
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_57
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_57
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_58
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_58
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_59
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_59
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_60
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_60
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_61
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_61
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_62
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_62
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_63
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_63
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_64
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_64
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_65
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_65
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_66
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_66
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_67
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_67
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_68
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_68
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_69
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_69
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_70
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_70
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_71
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_71
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_72
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_72
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_73
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_73
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_74
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_74
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_75
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_75
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_76
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_76
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_77
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_77
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_78
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_78
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_79
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_79
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_80
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_80
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_81
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_81
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_82
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_82
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_83
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_83
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_84
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_84
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_85
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_85
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_86
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_86
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_87
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_87
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_88
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_88
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_89
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_89
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_90
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_90
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_91
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_91
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_92
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_92
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_93
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_93
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_94
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_94
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_95
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_95
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_96
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_96
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_97
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_97
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_98
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_98
end_define

begin_define
define|#
directive|define
name|LLDB_API_NEW_IN_DOT_99
end_define

begin_define
define|#
directive|define
name|LLDB_API_DEPRECATED_IN_DOT_99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(LLDB_CHECK_API_VERSIONING)&& defined(LLDB_API_MAJOR_VERSION_WANTED)&& defined(LLDB_API_MINOR_VERSION_WANTED)&& defined (LLDB_API_MAJOR_VERSION)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_versioning_h_
end_comment

end_unit

