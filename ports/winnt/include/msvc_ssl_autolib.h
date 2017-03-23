begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * msvc_ssl_autolib.h -- automatic link library selection  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  * --------------------------------------------------------------------  *  * OpenSSL library names changed over time, at least once when v1.1.0  * emerged. For systems where the build system is inspected before  * the build environment is created (autconf, CMake, SCONS,...) this  * would be harmless, once it's known what libraries should be looked  * for. With MSVC / MSBUILD that's much trickier.  *  * So instead of manipulating the build environment we use the build  * tools themselves to create requests for linking the right library.  *  * To use this feature, it is recommended to use the precompiled  * VC binaries from Shining Light Productions:  *   https://slproweb.com/products/Win32OpenSSL.html  * These are installed in (OPENSSL_LIB)/vc.  *  * As an alternative, create the set of build variants of OpenSSL you  * need, implementing the following naming scheme:  *  *  basename<width><RT><DebRel>.lib  *  * so that e.g. libcrypto64MTd.lib is a 64bit binary, using a static  * multithreaded runtime in debug version. See the code below how this  * is handled.  * --------------------------------------------------------------------  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_error
error|#
directive|error
error|use this header only with Micro$oft Visual C compilers!
end_error

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSSL_NO_AUTOLINK
argument_list|)
end_elif

begin_pragma
pragma|#
directive|pragma
name|message
name|(
literal|"automatic OpenSSL library selection disabled"
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ---------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  selection dance to get the right libraries linked               */
end_comment

begin_comment
comment|/* ---------------------------------------------------------------- */
end_comment

begin_comment
comment|/* --*-- check if this a DEBUG or a RELEASE build --*--  * The '_DEBUG' macro is only set for DEBUG build variants  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|LTAG_DEBUG
value|"d"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LTAG_DEBUG
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --*-- check platform (32 bit vs. 64 bit) --*--  * '_WIN64' is defined for X64 Platform only  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_define
define|#
directive|define
name|LTAG_SIZE
value|"64"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LTAG_SIZE
value|"32"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --*-- check VC runtime model --*--  * '_DLL' is set if a runtime-in-a-dll code generation model is chosen.  * Note that we do not check for the single-threaded static runtime.  * This would make no sense, since the Windows Build *uses* threads and  * therefore needs a multithread runtime anyway. And Micro$oft decided  * somewhere after VS2008 to drop that model anyway, so it's no longer  * available on newer platforms.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DLL
end_ifdef

begin_empty
empty|#  #define LTAG_RTLIB "MD"
end_empty

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LTAG_RTLIB
value|"MT"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --*-- place linker request in object file --*--  * Here we come to the reason for all that trouble: the library names  * to link depend on the OpenSSL version...  *  * Before v1.1.0, the 'old' (ancient?) name 'libeay32' was used,  * no matter what platform. (The corresponding 'ssleay32.lib' was/is  * not used by NTP.) Since v1.1.0, the name stems are libcrypto  * and libssl, and they contain the platform size (32 or 64).  *  * So we use '#pragma comment(lib,...)' to place a proper linker  * request in the object file, depending on the SSL version and the  * build variant.  */
end_comment

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x10100000L
end_if

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"libcrypto"
name|LTAG_SIZE
name|LTAG_RTLIB
name|LTAG_DEBUG
literal|".lib"
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"libeay32"
name|LTAG_RTLIB
name|LTAG_DEBUG
literal|".lib"
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(OPENSSL_NO_AUTOLINK)*/
end_comment

end_unit

