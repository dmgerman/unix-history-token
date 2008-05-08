begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1998, 1999, 2000 Thai Open Source Software Center Ltd    See the file COPYING for copying permission. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Expat_External_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|Expat_External_INCLUDED
value|1
end_define

begin_comment
comment|/* External API definitions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__BEOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|XML_USE_MSC_EXTENSIONS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Expat tries very hard to make the API boundary very specifically    defined.  There are two macros defined to control this boundary;    each of these can be defined before including this header to    achieve some different behavior, but doing so it not recommended or    tested frequently.     XMLCALL    - The calling convention to use for all calls across the                 "library boundary."  This will default to cdecl, and                 try really hard to tell the compiler that's what we                 want.     XMLIMPORT  - Whatever magic is needed to note that a function is                 to be imported from a dynamically loaded library                 (.dll, .so, or .sl, depending on your platform).     The XMLCALL macro was added in Expat 1.95.7.  The only one which is    expected to be directly useful in client code is XMLCALL.     Note that on at least some Unix versions, the Expat library must be    compiled with the cdecl calling convention as the default since    system headers may assume the cdecl convention. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XMLCALL
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|XMLCALL
value|__cdecl
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__i386
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XMLCALL
value|__attribute__((cdecl))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* For any platform which uses this definition and supports more than    one calling convention, we need to extend this definition to    declare the convention used on that platform, if it's possible to    do so.     If this is the case for your platform, please file a bug report    with information on how to identify your platform via the C    pre-processor and how to specify the same calling convention as the    platform's malloc() implementation. */
end_comment

begin_define
define|#
directive|define
name|XMLCALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not defined XMLCALL */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XML_STATIC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XMLIMPORT
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|XML_BUILDING_EXPAT
end_ifndef

begin_comment
comment|/* using Expat from an application */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XML_USE_MSC_EXTENSIONS
end_ifdef

begin_define
define|#
directive|define
name|XMLIMPORT
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not defined XML_STATIC */
end_comment

begin_comment
comment|/* If we didn't define it above, define it away: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XMLIMPORT
end_ifndef

begin_define
define|#
directive|define
name|XMLIMPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XMLPARSEAPI
parameter_list|(
name|type
parameter_list|)
value|XMLIMPORT type XMLCALL
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XML_UNICODE_WCHAR_T
define|#
directive|define
name|XML_UNICODE
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XML_UNICODE
comment|/* Information is UTF-16 encoded. */
ifdef|#
directive|ifdef
name|XML_UNICODE_WCHAR_T
typedef|typedef
name|wchar_t
name|XML_Char
typedef|;
typedef|typedef
name|wchar_t
name|XML_LChar
typedef|;
else|#
directive|else
typedef|typedef
name|unsigned
name|short
name|XML_Char
typedef|;
typedef|typedef
name|char
name|XML_LChar
typedef|;
endif|#
directive|endif
comment|/* XML_UNICODE_WCHAR_T */
else|#
directive|else
comment|/* Information is UTF-8 encoded. */
typedef|typedef
name|char
name|XML_Char
typedef|;
typedef|typedef
name|char
name|XML_LChar
typedef|;
endif|#
directive|endif
comment|/* XML_UNICODE */
ifdef|#
directive|ifdef
name|XML_LARGE_SIZE
comment|/* Use large integers for file/stream positions. */
if|#
directive|if
name|defined
argument_list|(
name|XML_USE_MSC_EXTENSIONS
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1400
typedef|typedef
name|__int64
name|XML_Index
typedef|;
typedef|typedef
name|unsigned
name|__int64
name|XML_Size
typedef|;
else|#
directive|else
typedef|typedef
name|long
name|long
name|XML_Index
typedef|;
typedef|typedef
name|unsigned
name|long
name|long
name|XML_Size
typedef|;
endif|#
directive|endif
else|#
directive|else
typedef|typedef
name|long
name|XML_Index
typedef|;
typedef|typedef
name|unsigned
name|long
name|XML_Size
typedef|;
endif|#
directive|endif
comment|/* XML_LARGE_SIZE */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not Expat_External_INCLUDED */
end_comment

end_unit

