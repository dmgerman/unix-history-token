begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// $FreeBSD$
end_comment

begin_comment
comment|// Predefined symbols and macros -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CPPCONFIG
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CPPCONFIG
value|1
end_define

begin_comment
comment|// Pick up any OS-specific definitions.
end_comment

begin_include
include|#
directive|include
file|<bits/os_defines.h>
end_include

begin_comment
comment|// The current version of the C++ library in compressed ISO date format.
end_comment

begin_define
define|#
directive|define
name|__GLIBCPP__
value|20030513
end_define

begin_comment
comment|// This is necessary until GCC supports separate template compilation.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_NO_TEMPLATE_EXPORT
value|1
end_define

begin_comment
comment|// This is a hack around not having either pre-compiled headers or
end_comment

begin_comment
comment|// export compilation. If defined, the io, string, and valarray
end_comment

begin_comment
comment|// headers will include all the necessary bits. If not defined, the
end_comment

begin_comment
comment|// implementation optimizes the headers for the most commonly-used
end_comment

begin_comment
comment|// types. For the io library, this means that larger, out-of-line
end_comment

begin_comment
comment|// member functions are only declared, and definitions are not parsed
end_comment

begin_comment
comment|// by the compiler, but instead instantiated into the library binary.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_FULLY_COMPLIANT_HEADERS
value|1
end_define

begin_comment
comment|// Allow use of the GNU syntax extension, "extern template." This
end_comment

begin_comment
comment|// extension is fully documented in the g++ manual, but in a nutshell,
end_comment

begin_comment
comment|// it inhibits all implicit instantiations and is used throughout the
end_comment

begin_comment
comment|// library to avoid multiple weak definitions for required types that
end_comment

begin_comment
comment|// are already explicitly instantiated in the library binary. This
end_comment

begin_comment
comment|// substantially reduces the binary size of resulting executables.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_EXTERN_TEMPLATE
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCPP_EXTERN_TEMPLATE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// To enable older, ARM-style iostreams and other anachronisms use this.
end_comment

begin_comment
comment|//#define _GLIBCPP_DEPRECATED 1
end_comment

begin_comment
comment|// Use corrected code from the committee library group's issues list.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_RESOLVE_LIB_DEFECTS
value|1
end_define

begin_comment
comment|// Hopefully temporary workaround to autoconf/m4 issue with quoting '@'.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_AT_AT
value|"@@"
end_define

begin_comment
comment|// In those parts of the standard C++ library that use a mutex instead
end_comment

begin_comment
comment|// of a spin-lock, we now unconditionally use GCC's gthr.h mutex
end_comment

begin_comment
comment|// abstraction layer.  All support to directly map to various
end_comment

begin_comment
comment|// threading models has been removed.  Note: gthr.h may well map to
end_comment

begin_comment
comment|// gthr-single.h which is a correct way to express no threads support
end_comment

begin_comment
comment|// in gcc.  Support for the undocumented _NOTHREADS has been removed.
end_comment

begin_comment
comment|// Default to the typically high-speed, pool-based allocator (as
end_comment

begin_comment
comment|// libstdc++-v2) instead of the malloc-based allocator (libstdc++-v3
end_comment

begin_comment
comment|// snapshots).  See libstdc++-v3/docs/html/17_intro/howto.html for
end_comment

begin_comment
comment|// details on why you don't want to override this setting.  Ensure
end_comment

begin_comment
comment|// that threads are properly configured on your platform before
end_comment

begin_comment
comment|// assigning blame to the STL container-memory allocator.  After doing
end_comment

begin_comment
comment|// so, please report any possible issues to libstdc++@gcc.gnu.org .
end_comment

begin_comment
comment|// Do not define __USE_MALLOC on the command line.  Enforce it here:
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__USE_MALLOC
end_ifdef

begin_error
error|#
directive|error
error|__USE_MALLOC should never be defined.  Read the release notes.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Create a boolean flag to be used to determine if --fast-math is set.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FAST_MATH__
end_ifdef

begin_define
define|#
directive|define
name|_GLIBCPP_FAST_MATH
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GLIBCPP_FAST_MATH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The remainder of the prewritten config is mostly automatic; all the
end_comment

begin_comment
comment|// user hooks are listed above.
end_comment

begin_comment
comment|// End of prewritten config; the discovered settings follow.
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if you have a working `mmap' system call.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MMAP
value|1
end_define

begin_comment
comment|// Define if GCC supports weak symbols.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_SUPPORTS_WEAK
value|__GXX_WEAK__
end_define

begin_comment
comment|// Include I/O support for 'long long' and 'unsigned long long'.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_USE_LONG_LONG
value|1
end_define

begin_comment
comment|// Define if C99 features such as lldiv_t, llabs, lldiv should be exposed.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_USE_C99
value|1
end_define

begin_comment
comment|// Define if code specialized for wchar_t should be used.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_USE_WCHAR_T
value|1
end_define

begin_comment
comment|// Define if using setrlimit to limit memory usage during 'make check'.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_MEM_LIMITS */
end_comment

begin_comment
comment|// Define to use concept checking code from the boost libraries.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_CONCEPT_CHECKS */
end_comment

begin_comment
comment|// Define to use symbol versioning in the shared library.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_SYMVER */
end_comment

begin_comment
comment|// Define symbol versioning in assember directives. If symbol
end_comment

begin_comment
comment|// versioning is beigng used, and the assembler supports this kind of
end_comment

begin_comment
comment|// thing, then use it.
end_comment

begin_comment
comment|// NB: _GLIBCPP_AT_AT is a hack to work around quoting issues in m4.
end_comment

begin_if
if|#
directive|if
name|_GLIBCPP_SYMVER
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_ASM_SYMVER
parameter_list|(
name|cur
parameter_list|,
name|old
parameter_list|,
name|version
parameter_list|)
define|\
value|asm (".symver " #cur "," #old _GLIBCPP_AT_AT #version);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GLIBCPP_ASM_SYMVER
parameter_list|(
name|cur
parameter_list|,
name|old
parameter_list|,
name|version
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Define if gthr-default.h exists (meaning that threading support is enabled).
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_GTHR_DEFAULT
value|1
end_define

begin_comment
comment|// Define if drand48 exists.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_DRAND48
value|1
end_define

begin_comment
comment|// Define if getpagesize exists.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|// Define if setenv exists.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SETENV
value|1
end_define

begin_comment
comment|// Define if sigsetjmp exists.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SIGSETJMP
value|1
end_define

begin_comment
comment|// Define if mbstate_t exists in wchar.h.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MBSTATE_T
value|1
end_define

begin_comment
comment|// Define if you have the modff function.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MODFF
value|1
end_define

begin_comment
comment|// Define if you have the modfl function.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_MODFL */
end_comment

begin_comment
comment|// Define if you have the expf function.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_EXPF
value|1
end_define

begin_comment
comment|// Define if you have the expl function.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_EXPL */
end_comment

begin_comment
comment|// Define if you have the hypotf function.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_HYPOTF
value|1
end_define

begin_comment
comment|// Define if you have the hypotl function.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_HYPOTL */
end_comment

begin_comment
comment|// Define if the compiler/host combination has __builtin_abs
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_ABS
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_labs
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_LABS
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_cos
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_COS
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_cosf
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_COSF
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_cosl
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_COSL
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_fabs
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_FABS
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_fabsf
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_FABSF
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_fabsl
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_FABSL
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_sin
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_SIN
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_sinf
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_SINF
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_sinl
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___BUILTIN_SINL
value|1
end_define

begin_comment
comment|// Define if the compiler/host combination has __builtin_sqrt
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE___BUILTIN_SQRT */
end_comment

begin_comment
comment|// Define if the compiler/host combination has __builtin_sqrtf
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE___BUILTIN_SQRTF */
end_comment

begin_comment
comment|// Define if the compiler/host combination has __builtin_sqrtl
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE___BUILTIN_SQRTL */
end_comment

begin_comment
comment|// Define if poll is available in<poll.h>.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_POLL
value|1
end_define

begin_comment
comment|// Define if S_ISREG (Posix) is available in<sys/stat.h>.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_S_ISREG
value|1
end_define

begin_comment
comment|// Define if S_IFREG is available in<sys/stat.h>.
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_S_IFREG */
end_comment

begin_comment
comment|// Define if LC_MESSAGES is available in<locale.h>.
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define if you have the __signbit function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE___SIGNBIT
value|1
end_define

begin_comment
comment|/* Define if you have the __signbitf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE___SIGNBITF */
end_comment

begin_comment
comment|/* Define if you have the __signbitl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE___SIGNBITL */
end_comment

begin_comment
comment|/* Define if you have the _acosf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ACOSF */
end_comment

begin_comment
comment|/* Define if you have the _acosl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ACOSL */
end_comment

begin_comment
comment|/* Define if you have the _asinf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ASINF */
end_comment

begin_comment
comment|/* Define if you have the _asinl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ASINL */
end_comment

begin_comment
comment|/* Define if you have the _atan2f function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ATAN2F */
end_comment

begin_comment
comment|/* Define if you have the _atan2l function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ATAN2L */
end_comment

begin_comment
comment|/* Define if you have the _atanf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ATANF */
end_comment

begin_comment
comment|/* Define if you have the _atanl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ATANL */
end_comment

begin_comment
comment|/* Define if you have the _ceilf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__CEILF */
end_comment

begin_comment
comment|/* Define if you have the _ceill function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__CEILL */
end_comment

begin_comment
comment|/* Define if you have the _copysign function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__COPYSIGN */
end_comment

begin_comment
comment|/* Define if you have the _copysignl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__COPYSIGNL */
end_comment

begin_comment
comment|/* Define if you have the _cosf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__COSF */
end_comment

begin_comment
comment|/* Define if you have the _coshf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__COSHF */
end_comment

begin_comment
comment|/* Define if you have the _coshl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__COSHL */
end_comment

begin_comment
comment|/* Define if you have the _cosl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__COSL */
end_comment

begin_comment
comment|/* Define if you have the _expf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__EXPF */
end_comment

begin_comment
comment|/* Define if you have the _expl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__EXPL */
end_comment

begin_comment
comment|/* Define if you have the _fabsf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FABSF */
end_comment

begin_comment
comment|/* Define if you have the _fabsl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FABSL */
end_comment

begin_comment
comment|/* Define if you have the _finite function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FINITE */
end_comment

begin_comment
comment|/* Define if you have the _finitef function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FINITEF */
end_comment

begin_comment
comment|/* Define if you have the _finitel function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FINITEL */
end_comment

begin_comment
comment|/* Define if you have the _floorf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FLOORF */
end_comment

begin_comment
comment|/* Define if you have the _floorl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FLOORL */
end_comment

begin_comment
comment|/* Define if you have the _fmodf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FMODF */
end_comment

begin_comment
comment|/* Define if you have the _fmodl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FMODL */
end_comment

begin_comment
comment|/* Define if you have the _fpclass function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FPCLASS */
end_comment

begin_comment
comment|/* Define if you have the _frexpf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FREXPF */
end_comment

begin_comment
comment|/* Define if you have the _frexpl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__FREXPL */
end_comment

begin_comment
comment|/* Define if you have the _hypot function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__HYPOT */
end_comment

begin_comment
comment|/* Define if you have the _hypotf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__HYPOTF */
end_comment

begin_comment
comment|/* Define if you have the _hypotl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__HYPOTL */
end_comment

begin_comment
comment|/* Define if you have the _isinf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ISINF */
end_comment

begin_comment
comment|/* Define if you have the _isinff function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ISINFF */
end_comment

begin_comment
comment|/* Define if you have the _isinfl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ISINFL */
end_comment

begin_comment
comment|/* Define if you have the _isnan function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ISNAN */
end_comment

begin_comment
comment|/* Define if you have the _isnanf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ISNANF */
end_comment

begin_comment
comment|/* Define if you have the _isnanl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__ISNANL */
end_comment

begin_comment
comment|/* Define if you have the _ldexpf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__LDEXPF */
end_comment

begin_comment
comment|/* Define if you have the _ldexpl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__LDEXPL */
end_comment

begin_comment
comment|/* Define if you have the _log10f function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__LOG10F */
end_comment

begin_comment
comment|/* Define if you have the _log10l function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__LOG10L */
end_comment

begin_comment
comment|/* Define if you have the _logf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__LOGF */
end_comment

begin_comment
comment|/* Define if you have the _logl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__LOGL */
end_comment

begin_comment
comment|/* Define if you have the _modff function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__MODFF */
end_comment

begin_comment
comment|/* Define if you have the _modfl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__MODFL */
end_comment

begin_comment
comment|/* Define if you have the _powf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__POWF */
end_comment

begin_comment
comment|/* Define if you have the _powl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__POWL */
end_comment

begin_comment
comment|/* Define if you have the _qfpclass function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__QFPCLASS */
end_comment

begin_comment
comment|/* Define if you have the _sincos function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINCOS */
end_comment

begin_comment
comment|/* Define if you have the _sincosf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINCOSF */
end_comment

begin_comment
comment|/* Define if you have the _sincosl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINCOSL */
end_comment

begin_comment
comment|/* Define if you have the _sinf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINF */
end_comment

begin_comment
comment|/* Define if you have the _sinhf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINHF */
end_comment

begin_comment
comment|/* Define if you have the _sinhl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINHL */
end_comment

begin_comment
comment|/* Define if you have the _sinl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SINL */
end_comment

begin_comment
comment|/* Define if you have the _sqrtf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SQRTF */
end_comment

begin_comment
comment|/* Define if you have the _sqrtl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__SQRTL */
end_comment

begin_comment
comment|/* Define if you have the _tanf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__TANF */
end_comment

begin_comment
comment|/* Define if you have the _tanhf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__TANHF */
end_comment

begin_comment
comment|/* Define if you have the _tanhl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__TANHL */
end_comment

begin_comment
comment|/* Define if you have the _tanl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE__TANL */
end_comment

begin_comment
comment|/* Define if you have the acosf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ACOSF
value|1
end_define

begin_comment
comment|/* Define if you have the acosl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ACOSL */
end_comment

begin_comment
comment|/* Define if you have the asinf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ASINF
value|1
end_define

begin_comment
comment|/* Define if you have the asinl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ASINL */
end_comment

begin_comment
comment|/* Define if you have the atan2f function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ATAN2F
value|1
end_define

begin_comment
comment|/* Define if you have the atan2l function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ATAN2L */
end_comment

begin_comment
comment|/* Define if you have the atanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ATANF
value|1
end_define

begin_comment
comment|/* Define if you have the atanl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ATANL */
end_comment

begin_comment
comment|/* Define if you have the btowc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_BTOWC
value|1
end_define

begin_comment
comment|/* Define if you have the ceilf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_CEILF
value|1
end_define

begin_comment
comment|/* Define if you have the ceill function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_CEILL */
end_comment

begin_comment
comment|/* Define if you have the copysign function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COPYSIGN
value|1
end_define

begin_comment
comment|/* Define if you have the copysignf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COPYSIGNF
value|1
end_define

begin_comment
comment|/* Define if you have the copysignl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_COPYSIGNL */
end_comment

begin_comment
comment|/* Define if you have the cosf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COSF
value|1
end_define

begin_comment
comment|/* Define if you have the coshf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COSHF
value|1
end_define

begin_comment
comment|/* Define if you have the coshl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_COSHL */
end_comment

begin_comment
comment|/* Define if you have the cosl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_COSL */
end_comment

begin_comment
comment|/* Define if you have the drand48 function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_DRAND48
value|1
end_define

begin_comment
comment|/* Define if you have the expf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_EXPF
value|1
end_define

begin_comment
comment|/* Define if you have the expl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_EXPL */
end_comment

begin_comment
comment|/* Define if you have the fabsf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FABSF
value|1
end_define

begin_comment
comment|/* Define if you have the fabsl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FABSL */
end_comment

begin_comment
comment|/* Define if you have the fgetwc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FGETWC
value|1
end_define

begin_comment
comment|/* Define if you have the fgetws function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FGETWS
value|1
end_define

begin_comment
comment|/* Define if you have the finite function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FINITE
value|1
end_define

begin_comment
comment|/* Define if you have the finitef function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FINITEF
value|1
end_define

begin_comment
comment|/* Define if you have the finitel function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FINITEL */
end_comment

begin_comment
comment|/* Define if you have the floorf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FLOORF
value|1
end_define

begin_comment
comment|/* Define if you have the floorl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FLOORL */
end_comment

begin_comment
comment|/* Define if you have the fmodf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FMODF
value|1
end_define

begin_comment
comment|/* Define if you have the fmodl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FMODL */
end_comment

begin_comment
comment|/* Define if you have the fpclass function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FPCLASS */
end_comment

begin_comment
comment|/* Define if you have the fputwc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FPUTWC
value|1
end_define

begin_comment
comment|/* Define if you have the fputws function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FPUTWS
value|1
end_define

begin_comment
comment|/* Define if you have the frexpf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FREXPF
value|1
end_define

begin_comment
comment|/* Define if you have the frexpl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FREXPL */
end_comment

begin_comment
comment|/* Define if you have the fwide function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FWIDE
value|1
end_define

begin_comment
comment|/* Define if you have the fwprintf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FWPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the fwscanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FWSCANF
value|1
end_define

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getwc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_GETWC
value|1
end_define

begin_comment
comment|/* Define if you have the getwchar function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_GETWCHAR
value|1
end_define

begin_comment
comment|/* Define if you have the hypot function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_HYPOT
value|1
end_define

begin_comment
comment|/* Define if you have the hypotf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_HYPOTF
value|1
end_define

begin_comment
comment|/* Define if you have the hypotl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_HYPOTL */
end_comment

begin_comment
comment|/* Define if you have the iconv function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ICONV */
end_comment

begin_comment
comment|/* Define if you have the iconv_close function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ICONV_CLOSE */
end_comment

begin_comment
comment|/* Define if you have the iconv_open function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ICONV_OPEN */
end_comment

begin_comment
comment|/* Define if you have the isatty function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISATTY
value|1
end_define

begin_comment
comment|/* Define if you have the isinf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISINF
value|1
end_define

begin_comment
comment|/* Define if you have the isinff function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ISINFF */
end_comment

begin_comment
comment|/* Define if you have the isinfl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ISINFL */
end_comment

begin_comment
comment|/* Define if you have the isnan function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISNAN
value|1
end_define

begin_comment
comment|/* Define if you have the isnanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISNANF
value|1
end_define

begin_comment
comment|/* Define if you have the isnanl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ISNANL */
end_comment

begin_comment
comment|/* Define if you have the ldexpf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LDEXPF
value|1
end_define

begin_comment
comment|/* Define if you have the ldexpl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_LDEXPL */
end_comment

begin_comment
comment|/* Define if you have the log10f function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOG10F
value|1
end_define

begin_comment
comment|/* Define if you have the log10l function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_LOG10L */
end_comment

begin_comment
comment|/* Define if you have the logf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOGF
value|1
end_define

begin_comment
comment|/* Define if you have the logl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_LOGL */
end_comment

begin_comment
comment|/* Define if you have the mbrlen function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MBRLEN
value|1
end_define

begin_comment
comment|/* Define if you have the mbrtowc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MBRTOWC
value|1
end_define

begin_comment
comment|/* Define if you have the mbsinit function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MBSINIT
value|1
end_define

begin_comment
comment|/* Define if you have the mbsrtowcs function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MBSRTOWCS
value|1
end_define

begin_comment
comment|/* Define if you have the modff function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MODFF
value|1
end_define

begin_comment
comment|/* Define if you have the modfl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_MODFL */
end_comment

begin_comment
comment|/* Define if you have the nan function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_NAN */
end_comment

begin_comment
comment|/* Define if you have the nl_langinfo function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_NL_LANGINFO
value|1
end_define

begin_comment
comment|/* Define if you have the powf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_POWF
value|1
end_define

begin_comment
comment|/* Define if you have the powl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_POWL */
end_comment

begin_comment
comment|/* Define if you have the putwc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_PUTWC
value|1
end_define

begin_comment
comment|/* Define if you have the putwchar function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_PUTWCHAR
value|1
end_define

begin_comment
comment|/* Define if you have the qfpclass function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_QFPCLASS */
end_comment

begin_comment
comment|/* Define if you have the setenv function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the sincos function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SINCOS */
end_comment

begin_comment
comment|/* Define if you have the sincosf function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SINCOSF */
end_comment

begin_comment
comment|/* Define if you have the sincosl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SINCOSL */
end_comment

begin_comment
comment|/* Define if you have the sinf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINF
value|1
end_define

begin_comment
comment|/* Define if you have the sinhf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINHF
value|1
end_define

begin_comment
comment|/* Define if you have the sinhl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SINHL */
end_comment

begin_comment
comment|/* Define if you have the sinl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SINL */
end_comment

begin_comment
comment|/* Define if you have the sqrtf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SQRTF
value|1
end_define

begin_comment
comment|/* Define if you have the sqrtl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SQRTL */
end_comment

begin_comment
comment|/* Define if you have the strtof function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_STRTOF
value|1
end_define

begin_comment
comment|/* Define if you have the strtold function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_STRTOLD
value|1
end_define

begin_comment
comment|/* Define if you have the swprintf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SWPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the swscanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SWSCANF
value|1
end_define

begin_comment
comment|/* Define if you have the tanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_TANF
value|1
end_define

begin_comment
comment|/* Define if you have the tanhf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_TANHF
value|1
end_define

begin_comment
comment|/* Define if you have the tanhl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_TANHL */
end_comment

begin_comment
comment|/* Define if you have the tanl function.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_TANL */
end_comment

begin_comment
comment|/* Define if you have the ungetwc function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_UNGETWC
value|1
end_define

begin_comment
comment|/* Define if you have the vfwprintf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_VFWPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the vfwscanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_VFWSCANF
value|1
end_define

begin_comment
comment|/* Define if you have the vswprintf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_VSWPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the vswscanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_VSWSCANF
value|1
end_define

begin_comment
comment|/* Define if you have the vwprintf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_VWPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the vwscanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_VWSCANF
value|1
end_define

begin_comment
comment|/* Define if you have the wcrtomb function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCRTOMB
value|1
end_define

begin_comment
comment|/* Define if you have the wcscat function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSCAT
value|1
end_define

begin_comment
comment|/* Define if you have the wcschr function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSCHR
value|1
end_define

begin_comment
comment|/* Define if you have the wcscmp function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSCMP
value|1
end_define

begin_comment
comment|/* Define if you have the wcscoll function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSCOLL
value|1
end_define

begin_comment
comment|/* Define if you have the wcscpy function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSCPY
value|1
end_define

begin_comment
comment|/* Define if you have the wcscspn function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSCSPN
value|1
end_define

begin_comment
comment|/* Define if you have the wcsftime function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSFTIME
value|1
end_define

begin_comment
comment|/* Define if you have the wcslen function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSLEN
value|1
end_define

begin_comment
comment|/* Define if you have the wcsncat function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSNCAT
value|1
end_define

begin_comment
comment|/* Define if you have the wcsncmp function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSNCMP
value|1
end_define

begin_comment
comment|/* Define if you have the wcsncpy function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSNCPY
value|1
end_define

begin_comment
comment|/* Define if you have the wcspbrk function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSPBRK
value|1
end_define

begin_comment
comment|/* Define if you have the wcsrchr function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the wcsrtombs function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSRTOMBS
value|1
end_define

begin_comment
comment|/* Define if you have the wcsspn function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSSPN
value|1
end_define

begin_comment
comment|/* Define if you have the wcsstr function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSSTR
value|1
end_define

begin_comment
comment|/* Define if you have the wcstod function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSTOD
value|1
end_define

begin_comment
comment|/* Define if you have the wcstof function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSTOF
value|1
end_define

begin_comment
comment|/* Define if you have the wcstok function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSTOK
value|1
end_define

begin_comment
comment|/* Define if you have the wcstol function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSTOL
value|1
end_define

begin_comment
comment|/* Define if you have the wcstoul function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSTOUL
value|1
end_define

begin_comment
comment|/* Define if you have the wcsxfrm function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCSXFRM
value|1
end_define

begin_comment
comment|/* Define if you have the wctob function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCTOB
value|1
end_define

begin_comment
comment|/* Define if you have the wmemchr function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WMEMCHR
value|1
end_define

begin_comment
comment|/* Define if you have the wmemcmp function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WMEMCMP
value|1
end_define

begin_comment
comment|/* Define if you have the wmemcpy function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WMEMCPY
value|1
end_define

begin_comment
comment|/* Define if you have the wmemmove function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WMEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the wmemset function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WMEMSET
value|1
end_define

begin_comment
comment|/* Define if you have the wprintf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the wscanf function.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WSCANF
value|1
end_define

begin_comment
comment|/* Define if you have the<endian.h> header file.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_ENDIAN_H */
end_comment

begin_comment
comment|/* Define if you have the<float.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FLOAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fp.h> header file.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_FP_H */
end_comment

begin_comment
comment|/* Define if you have the<gconv.h> header file.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_GCONV_H */
end_comment

begin_comment
comment|/* Define if you have the<ieeefp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_IEEEFP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<inttypes.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<locale.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<machine/endian.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MACHINE_ENDIAN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<machine/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MACHINE_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nan.h> header file.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_NAN_H */
end_comment

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/filio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SYS_FILIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ioctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/isa_defs.h> header file.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SYS_ISA_DEFS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/machine.h> header file.  */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_HAVE_SYS_MACHINE_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<wchar.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<wctype.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_WCTYPE_H
value|1
end_define

begin_comment
comment|/* Define if you have the m library (-lm).  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LIBM
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_PACKAGE
value|"libstdc++"
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_VERSION
value|"3.3.1"
end_define

begin_comment
comment|/* Define if the compiler is configured for setjmp/longjmp exceptions. */
end_comment

begin_comment
comment|/* #undef _GLIBCPP_SJLJ_EXCEPTIONS */
end_comment

begin_comment
comment|/* Define if sigsetjmp is available.   */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SIGSETJMP
value|1
end_define

begin_comment
comment|/* Only used in build directory testsuite_hooks.h. */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MEMLIMIT_DATA
value|0
end_define

begin_comment
comment|/* Only used in build directory testsuite_hooks.h. */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MEMLIMIT_RSS
value|0
end_define

begin_comment
comment|/* Only used in build directory testsuite_hooks.h. */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MEMLIMIT_VMEM
value|0
end_define

begin_comment
comment|/* Only used in build directory testsuite_hooks.h. */
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MEMLIMIT_AS
value|0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Systems that have certain non-standard functions prefixed with an
end_comment

begin_comment
comment|// underscore, we'll handle those here. Must come after config.h.in.
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_GLIBCPP_HAVE__ISNAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ISNAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISNAN
value|1
end_define

begin_define
define|#
directive|define
name|isnan
value|_isnan
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
name|_GLIBCPP_HAVE__ISNANF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ISNANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISNANF
value|1
end_define

begin_define
define|#
directive|define
name|isnanf
value|_isnanf
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
name|_GLIBCPP_HAVE__ISNANL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ISNANL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISNANL
value|1
end_define

begin_define
define|#
directive|define
name|isnanl
value|_isnanl
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
name|_GLIBCPP_HAVE__ISINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ISINF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISINF
value|1
end_define

begin_define
define|#
directive|define
name|isinf
value|_isinf
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
name|_GLIBCPP_HAVE__ISINFF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ISINFF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISINFF
value|1
end_define

begin_define
define|#
directive|define
name|isinff
value|_isinff
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
name|_GLIBCPP_HAVE__ISINFL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ISINFL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ISINFL
value|1
end_define

begin_define
define|#
directive|define
name|isinfl
value|_isinfl
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
name|_GLIBCPP_HAVE__COPYSIGN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_COPYSIGN
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COPYSIGN
value|1
end_define

begin_define
define|#
directive|define
name|copysign
value|_copysign
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
name|_GLIBCPP_HAVE__COPYSIGNL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_COPYSIGNL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COPYSIGNL
value|1
end_define

begin_define
define|#
directive|define
name|copysignl
value|_copysignl
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
name|_GLIBCPP_HAVE__COSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_COSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COSF
value|1
end_define

begin_define
define|#
directive|define
name|cosf
value|_cosf
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
name|_GLIBCPP_HAVE__ACOSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ACOSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ACOSF
value|1
end_define

begin_define
define|#
directive|define
name|acosf
value|_acosf
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
name|_GLIBCPP_HAVE__ACOSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ACOSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ACOSL
value|1
end_define

begin_define
define|#
directive|define
name|acosl
value|_acosl
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
name|_GLIBCPP_HAVE__ASINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ASINF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ASINF
value|1
end_define

begin_define
define|#
directive|define
name|asinf
value|_asinf
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
name|_GLIBCPP_HAVE__ASINL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ASINL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ASINL
value|1
end_define

begin_define
define|#
directive|define
name|asinl
value|_asinl
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
name|_GLIBCPP_HAVE__ATANF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ATANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ATANF
value|1
end_define

begin_define
define|#
directive|define
name|atanf
value|_atanf
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
name|_GLIBCPP_HAVE__ATANL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_ATANL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_ATANL
value|1
end_define

begin_define
define|#
directive|define
name|atanl
value|_atanl
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
name|_GLIBCPP_HAVE__CEILF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_CEILF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_CEILF
value|1
end_define

begin_define
define|#
directive|define
name|aceil
value|_ceilf
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
name|_GLIBCPP_HAVE__CEILL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_CEILL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_CEILL
value|1
end_define

begin_define
define|#
directive|define
name|aceil
value|_ceill
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
name|_GLIBCPP_HAVE__COSHF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_COSHF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COSHF
value|1
end_define

begin_define
define|#
directive|define
name|coshf
value|_coshf
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
name|_GLIBCPP_HAVE__COSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_COSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COSL
value|1
end_define

begin_define
define|#
directive|define
name|cosl
value|_cosl
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
name|_GLIBCPP_HAVE__LOGF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_LOGF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOGF
value|1
end_define

begin_define
define|#
directive|define
name|logf
value|_logf
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
name|_GLIBCPP_HAVE__COSHL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_COSHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_COSHL
value|1
end_define

begin_define
define|#
directive|define
name|coshl
value|_coshl
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
name|_GLIBCPP_HAVE__EXPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_EXPF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_EXPF
value|1
end_define

begin_define
define|#
directive|define
name|expf
value|_expf
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
name|_GLIBCPP_HAVE__EXPL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_EXPL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_EXPL
value|1
end_define

begin_define
define|#
directive|define
name|expl
value|_expl
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
name|_GLIBCPP_HAVE__FABSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FABSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FABSF
value|1
end_define

begin_define
define|#
directive|define
name|fabsf
value|_fabsf
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
name|_GLIBCPP_HAVE__FABSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FABSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FABSL
value|1
end_define

begin_define
define|#
directive|define
name|fabsl
value|_fabsl
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
name|_GLIBCPP_HAVE__FLOORF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FLOORF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FLOORF
value|1
end_define

begin_define
define|#
directive|define
name|floorf
value|_floorf
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
name|_GLIBCPP_HAVE__FLOORL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FLOORL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FLOORL
value|1
end_define

begin_define
define|#
directive|define
name|floorl
value|_floorl
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
name|_GLIBCPP_HAVE__FMODF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FMODF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FMODF
value|1
end_define

begin_define
define|#
directive|define
name|fmodf
value|_fmodf
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
name|_GLIBCPP_HAVE__FMODL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FMODL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FMODL
value|1
end_define

begin_define
define|#
directive|define
name|fmodl
value|_fmodl
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
name|_GLIBCPP_HAVE__FREXPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FREXPF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FREXPF
value|1
end_define

begin_define
define|#
directive|define
name|frexpf
value|_frexpf
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
name|_GLIBCPP_HAVE__FREXPL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FREXPL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FREXPL
value|1
end_define

begin_define
define|#
directive|define
name|frexpl
value|_frexpl
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
name|_GLIBCPP_HAVE__LDEXPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_LDEXPF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LDEXPF
value|1
end_define

begin_define
define|#
directive|define
name|ldexpf
value|_ldexpf
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
name|_GLIBCPP_HAVE__LDEXPL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_LDEXPL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LDEXPL
value|1
end_define

begin_define
define|#
directive|define
name|ldexpl
value|_ldexpl
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
name|_GLIBCPP_HAVE__LOG10F
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_LOG10F
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOG10F
value|1
end_define

begin_define
define|#
directive|define
name|log10f
value|_log10f
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
name|_GLIBCPP_HAVE__LOGL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_LOGL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOGL
value|1
end_define

begin_define
define|#
directive|define
name|logl
value|_logl
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
name|_GLIBCPP_HAVE__POWF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_POWF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_POWF
value|1
end_define

begin_define
define|#
directive|define
name|powf
value|_powf
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
name|_GLIBCPP_HAVE__LOG10L
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_LOG10L
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_LOG10L
value|1
end_define

begin_define
define|#
directive|define
name|log10l
value|_log10l
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
name|_GLIBCPP_HAVE__MODF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_MODF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MODF
value|1
end_define

begin_define
define|#
directive|define
name|modf
value|_modf
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
name|_GLIBCPP_HAVE__MODL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_MODL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_MODL
value|1
end_define

begin_define
define|#
directive|define
name|modl
value|_modl
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
name|_GLIBCPP_HAVE__SINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINF
value|1
end_define

begin_define
define|#
directive|define
name|sinf
value|_sinf
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
name|_GLIBCPP_HAVE__POWL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_POWL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_POWL
value|1
end_define

begin_define
define|#
directive|define
name|powl
value|_powl
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
name|_GLIBCPP_HAVE__SINHF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINHF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINHF
value|1
end_define

begin_define
define|#
directive|define
name|sinhf
value|_sinhf
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
name|_GLIBCPP_HAVE__SINL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINL
value|1
end_define

begin_define
define|#
directive|define
name|sinl
value|_sinl
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
name|_GLIBCPP_HAVE__SQRTF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SQRTF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SQRTF
value|1
end_define

begin_define
define|#
directive|define
name|sqrtf
value|_sqrtf
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
name|_GLIBCPP_HAVE__SINHL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINHL
value|1
end_define

begin_define
define|#
directive|define
name|sinhl
value|_sinhl
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
name|_GLIBCPP_HAVE__TANF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_TANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_TANF
value|1
end_define

begin_define
define|#
directive|define
name|tanf
value|_tanf
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
name|_GLIBCPP_HAVE__SQRTL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SQRTL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SQRTL
value|1
end_define

begin_define
define|#
directive|define
name|sqrtl
value|_sqrtl
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
name|_GLIBCPP_HAVE__TANHF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_TANHF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_TANHF
value|1
end_define

begin_define
define|#
directive|define
name|tanhf
value|_tanhf
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
name|_GLIBCPP_HAVE__TANL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_TANL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_TANF
value|1
end_define

begin_define
define|#
directive|define
name|tanf
value|_tanf
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
name|_GLIBCPP_HAVE__STRTOF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_STRTOF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_STRTOF
value|1
end_define

begin_define
define|#
directive|define
name|strtof
value|_strtof
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
name|_GLIBCPP_HAVE__TANHL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_TANHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_TANHL
value|1
end_define

begin_define
define|#
directive|define
name|tanhl
value|_tanhl
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
name|_GLIBCPP_HAVE__STRTOLD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_STRTOLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_STRTOLD
value|1
end_define

begin_define
define|#
directive|define
name|strtold
value|_strtold
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
name|_GLIBCPP_HAVE__SINCOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINCOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINCOS
value|1
end_define

begin_define
define|#
directive|define
name|sincos
value|_sincos
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
name|_GLIBCPP_HAVE__SINCOSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINCOSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINCOSF
value|1
end_define

begin_define
define|#
directive|define
name|sincosf
value|_sincosf
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
name|_GLIBCPP_HAVE__SINCOSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_SINCOSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_SINCOSL
value|1
end_define

begin_define
define|#
directive|define
name|sincosl
value|_sincosl
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
name|_GLIBCPP_HAVE__FINITE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FINITE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FINITE
value|1
end_define

begin_define
define|#
directive|define
name|finite
value|_finite
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
name|_GLIBCPP_HAVE__FINITEF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FINITEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FINITEF
value|1
end_define

begin_define
define|#
directive|define
name|finitef
value|_finitef
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
name|_GLIBCPP_HAVE__FINITEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FINITEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FINITEL
value|1
end_define

begin_define
define|#
directive|define
name|finitel
value|_finitel
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
name|_GLIBCPP_HAVE__QFINITE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_QFINITE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_QFINITE
value|1
end_define

begin_define
define|#
directive|define
name|qfinite
value|_qfinite
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
name|_GLIBCPP_HAVE__FPCLASS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_FPCLASS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_FPCLASS
value|1
end_define

begin_define
define|#
directive|define
name|fpclass
value|_fpclass
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
name|_GLIBCPP_HAVE__QFPCLASS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GLIBCPP_HAVE_QFPCLASS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_HAVE_QFPCLASS
value|1
end_define

begin_define
define|#
directive|define
name|qfpclass
value|_qfpclass
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
comment|// _CPP_CPPCONFIG_
end_comment

end_unit

