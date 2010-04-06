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
name|TRANSFORMS_UTILS_BUILDLIBCALLS_H
end_ifndef

begin_define
define|#
directive|define
name|TRANSFORMS_UTILS_BUILDLIBCALLS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
comment|/// CastToCStr - Return V if it is an i8*, otherwise cast it to i8*.
name|Value
modifier|*
name|CastToCStr
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
comment|/// EmitStrLen - Emit a call to the strlen function to the builder, for the
comment|/// specified pointer.  Ptr is required to be some pointer type, and the
comment|/// return value has 'intptr_t' type.
name|Value
modifier|*
name|EmitStrLen
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitStrChr - Emit a call to the strchr function to the builder, for the
comment|/// specified pointer and character.  Ptr is required to be some pointer type,
comment|/// and the return value has 'i8*' type.
name|Value
modifier|*
name|EmitStrChr
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitStrCpy - Emit a call to the strcpy function to the builder, for the
comment|/// specified pointer arguments.
name|Value
modifier|*
name|EmitStrCpy
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
name|TargetData
operator|*
name|TD
argument_list|,
name|StringRef
name|Name
operator|=
literal|"strcpy"
argument_list|)
decl_stmt|;
comment|/// EmitStrNCpy - Emit a call to the strncpy function to the builder, for the
comment|/// specified pointer arguments and length.
name|Value
modifier|*
name|EmitStrNCpy
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitMemCpy - Emit a call to the memcpy function to the builder.  This
comment|/// always expects that the size has type 'intptr_t' and Dst/Src are pointers.
name|Value
modifier|*
name|EmitMemCpy
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
name|unsigned
name|Align
argument_list|,
name|bool
name|isVolatile
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitMemCpyChk - Emit a call to the __memcpy_chk function to the builder.
comment|/// This expects that the Len and ObjSize have type 'intptr_t' and Dst/Src
comment|/// are pointers.
name|Value
modifier|*
name|EmitMemCpyChk
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitMemMove - Emit a call to the memmove function to the builder.  This
comment|/// always expects that the size has type 'intptr_t' and Dst/Src are pointers.
name|Value
modifier|*
name|EmitMemMove
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
name|unsigned
name|Align
argument_list|,
name|bool
name|isVolatile
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitMemChr - Emit a call to the memchr function.  This assumes that Ptr is
comment|/// a pointer, Val is an i32 value, and Len is an 'intptr_t' value.
name|Value
modifier|*
name|EmitMemChr
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitMemCmp - Emit a call to the memcmp function.
name|Value
modifier|*
name|EmitMemCmp
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitMemSet - Emit a call to the memset function
name|Value
modifier|*
name|EmitMemSet
argument_list|(
name|Value
operator|*
name|Dst
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Len
argument_list|,
name|bool
name|isVolatile
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitUnaryFloatFnCall - Emit a call to the unary function named 'Name'
comment|/// (e.g.  'floor').  This function is known to take a single of type matching
comment|/// 'Op' and returns one value with the same type.  If 'Op' is a long double,
comment|/// 'l' is added as the suffix of name, if 'Op' is a float, we add a 'f'
comment|/// suffix.
name|Value
modifier|*
name|EmitUnaryFloatFnCall
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|B
argument_list|,
specifier|const
name|AttrListPtr
operator|&
name|Attrs
argument_list|)
decl_stmt|;
comment|/// EmitPutChar - Emit a call to the putchar function.  This assumes that Char
comment|/// is an integer.
name|Value
modifier|*
name|EmitPutChar
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitPutS - Emit a call to the puts function.  This assumes that Str is
comment|/// some pointer.
name|void
name|EmitPutS
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitFPutC - Emit a call to the fputc function.  This assumes that Char is
comment|/// an i32, and File is a pointer to FILE.
name|void
name|EmitFPutC
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitFPutS - Emit a call to the puts function.  Str is required to be a
comment|/// pointer and File is a pointer to FILE.
name|void
name|EmitFPutS
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// EmitFWrite - Emit a call to the fwrite function.  This assumes that Ptr is
comment|/// a pointer, Size is an 'intptr_t', and File is a pointer to FILE.
name|void
name|EmitFWrite
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
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// SimplifyFortifiedLibCalls - Helper class for folding checked library
comment|/// calls (e.g. __strcpy_chk) into their unchecked counterparts.
name|class
name|SimplifyFortifiedLibCalls
block|{
name|protected
label|:
name|CallInst
modifier|*
name|CI
decl_stmt|;
name|virtual
name|void
name|replaceCall
parameter_list|(
name|Value
modifier|*
name|With
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|isFoldable
argument_list|(
name|unsigned
name|SizeCIOp
argument_list|,
name|unsigned
name|SizeArgOp
argument_list|,
name|bool
name|isString
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|SimplifyFortifiedLibCalls
argument_list|()
expr_stmt|;
name|bool
name|fold
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

