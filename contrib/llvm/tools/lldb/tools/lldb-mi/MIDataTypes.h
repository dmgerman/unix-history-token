begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIDataTypes.h -------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//++
end_comment

begin_comment
comment|// File:        MIDataTypes.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    Common global switches, macros, etc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//              This file contains common data types required by applications
end_comment

begin_comment
comment|//              generally. If supported by the compiler, this file should be
end_comment

begin_comment
comment|//              #include'd as part of the project's PCH (precompiled header).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|//--------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Windows headers:
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_comment
comment|// Debugging:
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<crtdbg.h>
end_include

begin_comment
comment|// C-runtime debugging library (defines _ASSERT).
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _DEBUG
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32
end_comment

begin_comment
comment|//--------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Common definitions:
end_comment

begin_comment
comment|// Function return status
end_comment

begin_decl_stmt
name|namespace
name|MIstatus
block|{
specifier|const
name|bool
name|success
init|=
name|true
decl_stmt|;
specifier|const
name|bool
name|failure
init|=
name|false
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Use to avoid "unused parameter" compiler warnings:
end_comment

begin_define
define|#
directive|define
name|MIunused
parameter_list|(
name|x
parameter_list|)
value|(void) x;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|MI_NO_INITIALIZE_VTABLE
value|__declspec(novtable)
end_define

begin_define
define|#
directive|define
name|MI_FORCE_INLINE
value|__forceinline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MI_NO_INITIALIZE_VTABLE
end_define

begin_define
define|#
directive|define
name|MI_FORCE_INLINE
value|inline
end_define

begin_comment
comment|// __attribute__( ( always_inline ) )
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32
end_comment

begin_comment
comment|// Portability issues
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|PointerToInteger_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|MIint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|MIuint
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|PointerToInteger_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MIint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|MIuint
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|//       typedef     long unsigned int size_t; // size_t already defined
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|PointerToInteger_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MIint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|MIuint
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_PATH
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN64
end_comment

begin_comment
comment|//--------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Common types:
end_comment

begin_comment
comment|// Fundamentals:
end_comment

begin_typedef
typedef|typedef
name|float
name|MIflt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|MIdbl
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|MIchar
typedef|;
end_typedef

begin_comment
comment|// Defaults to signed char, i.e. MIschar.
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|MIschar
typedef|;
end_typedef

begin_comment
comment|// Range: -128 to 127. More explicit than using MIchar.
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|MIuchar
typedef|;
end_typedef

begin_comment
comment|// Range: 0 to 255.
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|MIint64
typedef|;
end_typedef

begin_comment
comment|// 64bit signed integer.
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|MIuint64
typedef|;
end_typedef

begin_comment
comment|// 64bit unsigned integer.
end_comment

begin_comment
comment|// using namespace std; // Better to put this or std:: at translation units scope.
end_comment

begin_comment
comment|//--------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Common routines:
end_comment

begin_comment
comment|//--------------------------------------------------------------------------------------
end_comment

end_unit

