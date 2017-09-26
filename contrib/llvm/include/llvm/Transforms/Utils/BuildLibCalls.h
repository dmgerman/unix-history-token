begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BuildLibCalls.h - Utility builder for libcalls -----------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file exposes an interface to build some C language libcalls for
end_comment

begin_comment
comment|// optimization passes that need to call the various functions.
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
name|LLVM_TRANSFORMS_UTILS_BUILDLIBCALLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_BUILDLIBCALLS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
comment|/// Analyze the name and prototype of the given function and set any
comment|/// applicable attributes.
comment|/// If the library function is unavailable, this doesn't modify it.
comment|///
comment|/// Returns true if any attributes were set and false otherwise.
name|bool
name|inferLibFuncAttributes
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|&
name|TLI
parameter_list|)
function_decl|;
comment|/// Return V if it is an i8*, otherwise cast it to i8*.
name|Value
modifier|*
name|castToCStr
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|)
decl_stmt|;
comment|/// Emit a call to the strlen function to the builder, for the specified
comment|/// pointer. Ptr is required to be some pointer type, and the return value has
comment|/// 'intptr_t' type.
name|Value
modifier|*
name|emitStrLen
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the strnlen function to the builder, for the specified
comment|/// pointer. Ptr is required to be some pointer type, MaxLen must be of size_t
comment|/// type, and the return value has 'intptr_t' type.
name|Value
modifier|*
name|emitStrNLen
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|Value
operator|*
name|MaxLen
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the strchr function to the builder, for the specified
comment|/// pointer and character. Ptr is required to be some pointer type, and the
comment|/// return value has 'i8*' type.
name|Value
modifier|*
name|emitStrChr
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|char
name|C
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the strncmp function to the builder.
name|Value
modifier|*
name|emitStrNCmp
argument_list|(
name|Value
operator|*
name|Ptr1
argument_list|,
name|Value
operator|*
name|Ptr2
argument_list|,
name|Value
operator|*
name|Len
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the strcpy function to the builder, for the specified
comment|/// pointer arguments.
name|Value
modifier|*
name|emitStrCpy
argument_list|(
name|Value
operator|*
name|Dst
argument_list|,
name|Value
operator|*
name|Src
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|,
name|StringRef
name|Name
operator|=
literal|"strcpy"
argument_list|)
decl_stmt|;
comment|/// Emit a call to the strncpy function to the builder, for the specified
comment|/// pointer arguments and length.
name|Value
modifier|*
name|emitStrNCpy
argument_list|(
name|Value
operator|*
name|Dst
argument_list|,
name|Value
operator|*
name|Src
argument_list|,
name|Value
operator|*
name|Len
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|,
name|StringRef
name|Name
operator|=
literal|"strncpy"
argument_list|)
decl_stmt|;
comment|/// Emit a call to the __memcpy_chk function to the builder. This expects that
comment|/// the Len and ObjSize have type 'intptr_t' and Dst/Src are pointers.
name|Value
modifier|*
name|emitMemCpyChk
argument_list|(
name|Value
operator|*
name|Dst
argument_list|,
name|Value
operator|*
name|Src
argument_list|,
name|Value
operator|*
name|Len
argument_list|,
name|Value
operator|*
name|ObjSize
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the memchr function. This assumes that Ptr is a pointer,
comment|/// Val is an i32 value, and Len is an 'intptr_t' value.
name|Value
modifier|*
name|emitMemChr
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Len
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the memcmp function.
name|Value
modifier|*
name|emitMemCmp
argument_list|(
name|Value
operator|*
name|Ptr1
argument_list|,
name|Value
operator|*
name|Ptr2
argument_list|,
name|Value
operator|*
name|Len
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the unary function named 'Name' (e.g.  'floor'). This
comment|/// function is known to take a single of type matching 'Op' and returns one
comment|/// value with the same type. If 'Op' is a long double, 'l' is added as the
comment|/// suffix of name, if 'Op' is a float, we add a 'f' suffix.
name|Value
modifier|*
name|emitUnaryFloatFnCall
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
name|StringRef
name|Name
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|AttributeList
operator|&
name|Attrs
argument_list|)
decl_stmt|;
comment|/// Emit a call to the binary function named 'Name' (e.g. 'fmin'). This
comment|/// function is known to take type matching 'Op1' and 'Op2' and return one
comment|/// value with the same type. If 'Op1/Op2' are long double, 'l' is added as
comment|/// the suffix of name, if 'Op1/Op2' are float, we add a 'f' suffix.
name|Value
modifier|*
name|emitBinaryFloatFnCall
argument_list|(
name|Value
operator|*
name|Op1
argument_list|,
name|Value
operator|*
name|Op2
argument_list|,
name|StringRef
name|Name
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|AttributeList
operator|&
name|Attrs
argument_list|)
decl_stmt|;
comment|/// Emit a call to the putchar function. This assumes that Char is an integer.
name|Value
modifier|*
name|emitPutChar
argument_list|(
name|Value
operator|*
name|Char
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the puts function. This assumes that Str is some pointer.
name|Value
modifier|*
name|emitPutS
argument_list|(
name|Value
operator|*
name|Str
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the fputc function. This assumes that Char is an i32, and
comment|/// File is a pointer to FILE.
name|Value
modifier|*
name|emitFPutC
argument_list|(
name|Value
operator|*
name|Char
argument_list|,
name|Value
operator|*
name|File
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the puts function. Str is required to be a pointer and
comment|/// File is a pointer to FILE.
name|Value
modifier|*
name|emitFPutS
argument_list|(
name|Value
operator|*
name|Str
argument_list|,
name|Value
operator|*
name|File
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
comment|/// Emit a call to the fwrite function. This assumes that Ptr is a pointer,
comment|/// Size is an 'intptr_t', and File is a pointer to FILE.
name|Value
modifier|*
name|emitFWrite
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|Value
operator|*
name|Size
argument_list|,
name|Value
operator|*
name|File
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

