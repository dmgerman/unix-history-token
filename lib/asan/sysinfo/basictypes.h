begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright (c) 2005, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BASICTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_BASICTYPES_H_
end_define

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|// uint16_t might be here; PRId64 too.
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// to get uint16_t (ISO naming madness)
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|// our last best hope for uint16_t
end_comment

begin_comment
comment|// Standard typedefs
end_comment

begin_comment
comment|// All Google code is compiled with -funsigned-char to make "char"
end_comment

begin_comment
comment|// unsigned.  Google code therefore doesn't need a "uchar" type.
end_comment

begin_comment
comment|// TODO(csilvers): how do we make sure unsigned-char works on non-gcc systems?
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|schar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|int64
typedef|;
end_typedef

begin_comment
comment|// NOTE: unsigned types are DANGEROUS in loops and other arithmetical
end_comment

begin_comment
comment|// places.  Use the signed types unless your variable represents a bit
end_comment

begin_comment
comment|// pattern (eg a hash value) or you really need the extra bit.  Do NOT
end_comment

begin_comment
comment|// use 'unsigned' to express "this value should always be positive";
end_comment

begin_comment
comment|// use assertions for this.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|uint16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|uint64
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|uint16
name|kuint16max
init|=
operator|(
operator|(
name|uint16
operator|)
literal|0xFFFF
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uint32
name|kuint32max
init|=
operator|(
operator|(
name|uint32
operator|)
literal|0xFFFFFFFF
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uint64
name|kuint64max
init|=
operator|(
operator|(
operator|(
operator|(
name|uint64
operator|)
name|kuint32max
operator|)
operator|<<
literal|32
operator|)
operator||
name|kuint32max
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int8
name|kint8max
init|=
operator|(
operator|(
name|int8
operator|)
literal|0x7F
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int16
name|kint16max
init|=
operator|(
operator|(
name|int16
operator|)
literal|0x7FFF
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int32
name|kint32max
init|=
operator|(
operator|(
name|int32
operator|)
literal|0x7FFFFFFF
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int64
name|kint64max
init|=
operator|(
operator|(
operator|(
operator|(
name|int64
operator|)
name|kint32max
operator|)
operator|<<
literal|32
operator|)
operator||
name|kuint32max
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int8
name|kint8min
init|=
operator|(
operator|(
name|int8
operator|)
literal|0x80
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int16
name|kint16min
init|=
operator|(
operator|(
name|int16
operator|)
literal|0x8000
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int32
name|kint32min
init|=
operator|(
operator|(
name|int32
operator|)
literal|0x80000000
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int64
name|kint64min
init|=
operator|(
operator|(
operator|(
operator|(
name|int64
operator|)
name|kint32min
operator|)
operator|<<
literal|32
operator|)
operator||
literal|0
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Define the "portable" printf and scanf macros, if they're not
end_comment

begin_comment
comment|// already there (via the inttypes.h we #included above, hopefully).
end_comment

begin_comment
comment|// Mostly it's old systems that don't support inttypes.h, so we assume
end_comment

begin_comment
comment|// they're 32 bit.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PRIx64
end_ifndef

begin_define
define|#
directive|define
name|PRIx64
value|"llx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCNx64
end_ifndef

begin_define
define|#
directive|define
name|SCNx64
value|"llx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRId64
end_ifndef

begin_define
define|#
directive|define
name|PRId64
value|"lld"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCNd64
end_ifndef

begin_define
define|#
directive|define
name|SCNd64
value|"lld"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIu64
end_ifndef

begin_define
define|#
directive|define
name|PRIu64
value|"llu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIxPTR
end_ifndef

begin_define
define|#
directive|define
name|PRIxPTR
value|"lx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Also allow for printing of a pthread_t.
end_comment

begin_define
define|#
directive|define
name|GPRIuPTHREAD
value|"lu"
end_define

begin_define
define|#
directive|define
name|GPRIxPTHREAD
value|"lx"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PRINTABLE_PTHREAD
parameter_list|(
name|pthreadt
parameter_list|)
value|reinterpret_cast<uintptr_t>(pthreadt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINTABLE_PTHREAD
parameter_list|(
name|pthreadt
parameter_list|)
value|pthreadt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// A macro to disallow the evil copy constructor and operator= functions
end_comment

begin_comment
comment|// This should be used in the private: declarations for a class
end_comment

begin_define
define|#
directive|define
name|DISALLOW_EVIL_CONSTRUCTORS
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|TypeName(const TypeName&);                    \   void operator=(const TypeName&)
end_define

begin_comment
comment|// An alternate name that leaves out the moral judgment... :-)
end_comment

begin_define
define|#
directive|define
name|DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TypeName
parameter_list|)
value|DISALLOW_EVIL_CONSTRUCTORS(TypeName)
end_define

begin_comment
comment|// The COMPILE_ASSERT macro can be used to verify that a compile time
end_comment

begin_comment
comment|// expression is true. For example, you could use it to verify the
end_comment

begin_comment
comment|// size of a static array:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   COMPILE_ASSERT(sizeof(num_content_type_names) == sizeof(int),
end_comment

begin_comment
comment|//                  content_type_names_incorrect_size);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// or to make sure a struct is smaller than a certain size:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   COMPILE_ASSERT(sizeof(foo)< 128, foo_too_large);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The second argument to the macro is the name of the variable. If
end_comment

begin_comment
comment|// the expression is false, most compilers will issue a warning/error
end_comment

begin_comment
comment|// containing the name of the variable.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Implementation details of COMPILE_ASSERT:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - COMPILE_ASSERT works by defining an array type that has -1
end_comment

begin_comment
comment|//   elements (and thus is invalid) when the expression is false.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - The simpler definition
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     #define COMPILE_ASSERT(expr, msg) typedef char msg[(expr) ? 1 : -1]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   does not work, as gcc supports variable-length arrays whose sizes
end_comment

begin_comment
comment|//   are determined at run-time (this is gcc's extension and not part
end_comment

begin_comment
comment|//   of the C++ standard).  As a result, gcc fails to reject the
end_comment

begin_comment
comment|//   following code with the simple definition:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     int foo;
end_comment

begin_comment
comment|//     COMPILE_ASSERT(foo, msg); // not supposed to compile as foo is
end_comment

begin_comment
comment|//                               // not a compile-time constant.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - By using the type CompileAssert<(bool(expr))>, we ensures that
end_comment

begin_comment
comment|//   expr is a compile-time constant.  (Template arguments must be
end_comment

begin_comment
comment|//   determined at compile-time.)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - The outter parentheses in CompileAssert<(bool(expr))> are necessary
end_comment

begin_comment
comment|//   to work around a bug in gcc 3.4.4 and 4.0.1.  If we had written
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     CompileAssert<bool(expr)>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   instead, these compilers will refuse to compile
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     COMPILE_ASSERT(5> 0, some_message);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   (They seem to think the ">" in "5> 0" marks the end of the
end_comment

begin_comment
comment|//   template argument list.)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - The array size is (bool(expr) ? 1 : -1), instead of simply
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     ((expr) ? 1 : -1).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   This is to avoid running into a bug in MS VC 7.1, which
end_comment

begin_comment
comment|//   causes ((0.0) ? 1 : -1) to incorrectly evaluate to 1.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
operator|>
expr|struct
name|CompileAssert
block|{ }
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|COMPILE_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
define|\
value|typedef CompileAssert<(bool(expr))> msg[bool(expr) ? 1 : -1]
end_define

begin_define
define|#
directive|define
name|arraysize
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof(*(a)))
end_define

begin_define
define|#
directive|define
name|OFFSETOF_MEMBER
parameter_list|(
name|strct
parameter_list|,
name|field
parameter_list|)
define|\
value|(reinterpret_cast<char*>(&reinterpret_cast<strct*>(16)->field) -     \     reinterpret_cast<char*>(16))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE___ATTRIBUTE__
end_ifdef

begin_define
define|#
directive|define
name|ATTRIBUTE_WEAK
value|__attribute__((weak))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_NOINLINE
value|__attribute__((noinline))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_WEAK
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_NOINLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Section attributes are supported for both ELF and Mach-O, but in
end_comment

begin_comment
comment|// very different ways.  Here's the API we provide:
end_comment

begin_comment
comment|// 1) ATTRIBUTE_SECTION: put this with the declaration of all functions
end_comment

begin_comment
comment|//    you want to be in the same linker section
end_comment

begin_comment
comment|// 2) DEFINE_ATTRIBUTE_SECTION_VARS: must be called once per unique
end_comment

begin_comment
comment|//    name.  You want to make sure this is executed before any
end_comment

begin_comment
comment|//    DECLARE_ATTRIBUTE_SECTION_VARS; the easiest way is to put them
end_comment

begin_comment
comment|//    in the same .cc file.  Put this call at the global level.
end_comment

begin_comment
comment|// 3) INIT_ATTRIBUTE_SECTION_VARS: you can scatter calls to this in
end_comment

begin_comment
comment|//    multiple places to help ensure execution before any
end_comment

begin_comment
comment|//    DECLARE_ATTRIBUTE_SECTION_VARS.  You must have at least one
end_comment

begin_comment
comment|//    DEFINE, but you can have many INITs.  Put each in its own scope.
end_comment

begin_comment
comment|// 4) DECLARE_ATTRIBUTE_SECTION_VARS: must be called before using
end_comment

begin_comment
comment|//    ATTRIBUTE_SECTION_START or ATTRIBUTE_SECTION_STOP on a name.
end_comment

begin_comment
comment|//    Put this call at the global level.
end_comment

begin_comment
comment|// 5) ATTRIBUTE_SECTION_START/ATTRIBUTE_SECTION_STOP: call this to say
end_comment

begin_comment
comment|//    where in memory a given section is.  All functions declared with
end_comment

begin_comment
comment|//    ATTRIBUTE_SECTION are guaranteed to be between START and STOP.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE___ATTRIBUTE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION
parameter_list|(
name|name
parameter_list|)
value|__attribute__ ((section (#name)))
end_define

begin_comment
comment|// Weak section declaration to be used as a global declaration
end_comment

begin_comment
comment|// for ATTRIBUTE_SECTION_START|STOP(name) to compile and link
end_comment

begin_comment
comment|// even without functions with ATTRIBUTE_SECTION(name).
end_comment

begin_define
define|#
directive|define
name|DECLARE_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
define|\
value|extern char __start_##name[] ATTRIBUTE_WEAK; \     extern char __stop_##name[] ATTRIBUTE_WEAK
end_define

begin_define
define|#
directive|define
name|INIT_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
end_define

begin_comment
comment|// no-op for ELF
end_comment

begin_define
define|#
directive|define
name|DEFINE_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
end_define

begin_comment
comment|// no-op for ELF
end_comment

begin_comment
comment|// Return void* pointers to start/end of a section of code with functions
end_comment

begin_comment
comment|// having ATTRIBUTE_SECTION(name), or 0 if no such function exists.
end_comment

begin_comment
comment|// One must DECLARE_ATTRIBUTE_SECTION(name) for this to compile and link.
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION_START
parameter_list|(
name|name
parameter_list|)
value|(reinterpret_cast<void*>(__start_##name))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION_STOP
parameter_list|(
name|name
parameter_list|)
value|(reinterpret_cast<void*>(__stop_##name))
end_define

begin_define
define|#
directive|define
name|HAVE_ATTRIBUTE_SECTION_START
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE___ATTRIBUTE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__MACH__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION
parameter_list|(
name|name
parameter_list|)
value|__attribute__ ((section ("__TEXT, " #name)))
end_define

begin_include
include|#
directive|include
file|<mach-o/getsect.h>
end_include

begin_include
include|#
directive|include
file|<mach-o/dyld.h>
end_include

begin_decl_stmt
name|class
name|AssignAttributeStartEnd
block|{
name|public
label|:
name|AssignAttributeStartEnd
argument_list|(
argument|const char* name
argument_list|,
argument|char** pstart
argument_list|,
argument|char** pend
argument_list|)
block|{
comment|// Find out what dynamic library name is defined in
if|if
condition|(
name|_dyld_present
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|_dyld_image_count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
specifier|const
name|mach_header
modifier|*
name|hdr
init|=
name|_dyld_get_image_header
argument_list|(
name|i
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|MH_MAGIC_64
if|if
condition|(
name|hdr
operator|->
name|magic
operator|==
name|MH_MAGIC_64
condition|)
block|{
name|uint64_t
name|len
decl_stmt|;
operator|*
name|pstart
operator|=
name|getsectdatafromheader_64
argument_list|(
operator|(
name|mach_header_64
operator|*
operator|)
name|hdr
argument_list|,
literal|"__TEXT"
argument_list|,
name|name
argument_list|,
operator|&
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|pstart
condition|)
block|{
comment|// NULL if not defined in this dynamic library
operator|*
name|pstart
operator|+=
name|_dyld_get_image_vmaddr_slide
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|// correct for reloc
operator|*
name|pend
operator|=
operator|*
name|pstart
operator|+
name|len
expr_stmt|;
return|return;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
name|hdr
operator|->
name|magic
operator|==
name|MH_MAGIC
condition|)
block|{
name|uint32_t
name|len
decl_stmt|;
operator|*
name|pstart
operator|=
name|getsectdatafromheader
argument_list|(
name|hdr
argument_list|,
literal|"__TEXT"
argument_list|,
name|name
argument_list|,
operator|&
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|pstart
condition|)
block|{
comment|// NULL if not defined in this dynamic library
operator|*
name|pstart
operator|+=
name|_dyld_get_image_vmaddr_slide
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|// correct for reloc
operator|*
name|pend
operator|=
operator|*
name|pstart
operator|+
name|len
expr_stmt|;
return|return;
block|}
block|}
block|}
block|}
comment|// If we get here, not defined in a dll at all.  See if defined statically.
name|unsigned
name|long
name|len
decl_stmt|;
comment|// don't ask me why this type isn't uint32_t too...
operator|*
name|pstart
operator|=
name|getsectdata
argument_list|(
literal|"__TEXT"
argument_list|,
name|name
argument_list|,
operator|&
name|len
argument_list|)
expr_stmt|;
operator|*
name|pend
operator|=
operator|*
name|pstart
operator|+
name|len
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|DECLARE_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
define|\
value|extern char* __start_##name;                  \   extern char* __stop_##name
end_define

begin_define
define|#
directive|define
name|INIT_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
define|\
value|DECLARE_ATTRIBUTE_SECTION_VARS(name);                 \   static const AssignAttributeStartEnd __assign_##name( \     #name,&__start_##name,&__stop_##name)
end_define

begin_define
define|#
directive|define
name|DEFINE_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
define|\
value|char* __start_##name, *__stop_##name;         \   INIT_ATTRIBUTE_SECTION_VARS(name)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION_START
parameter_list|(
name|name
parameter_list|)
value|(reinterpret_cast<void*>(__start_##name))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION_STOP
parameter_list|(
name|name
parameter_list|)
value|(reinterpret_cast<void*>(__stop_##name))
end_define

begin_define
define|#
directive|define
name|HAVE_ATTRIBUTE_SECTION_START
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// not HAVE___ATTRIBUTE__&& __ELF__, nor HAVE___ATTRIBUTE__&& __MACH__
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DECLARE_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INIT_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEFINE_ATTRIBUTE_SECTION_VARS
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION_START
parameter_list|(
name|name
parameter_list|)
value|(reinterpret_cast<void*>(0))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_SECTION_STOP
parameter_list|(
name|name
parameter_list|)
value|(reinterpret_cast<void*>(0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// HAVE___ATTRIBUTE__ and __ELF__ or __MACH__
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE___ATTRIBUTE__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|CACHELINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|CACHELINE_ALIGNED
value|__attribute__((aligned(CACHELINE_SIZE)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CACHELINE_ALIGNED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(HAVE___ATTRIBUTE__)&& (__i386__ || __x86_64__)
end_comment

begin_comment
comment|// The following enum should be used only as a constructor argument to indicate
end_comment

begin_comment
comment|// that the variable has static storage class, and that the constructor should
end_comment

begin_comment
comment|// do nothing to its state.  It indicates to the reader that it is legal to
end_comment

begin_comment
comment|// declare a static nistance of the class, provided the constructor is given
end_comment

begin_comment
comment|// the base::LINKER_INITIALIZED argument.  Normally, it is unsafe to declare a
end_comment

begin_comment
comment|// static variable that has a constructor or a destructor because invocation
end_comment

begin_comment
comment|// order is undefined.  However, IF the type can be initialized by filling with
end_comment

begin_comment
comment|// zeroes (which the loader does for static variables), AND the destructor also
end_comment

begin_comment
comment|// does nothing to the storage, then a constructor declared as
end_comment

begin_comment
comment|//       explicit MyClass(base::LinkerInitialized x) {}
end_comment

begin_comment
comment|// and invoked as
end_comment

begin_comment
comment|//       static MyClass my_variable_name(base::LINKER_INITIALIZED);
end_comment

begin_decl_stmt
name|namespace
name|base
block|{
enum|enum
name|LinkerInitialized
block|{
name|LINKER_INITIALIZED
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _BASICTYPES_H_
end_comment

end_unit

