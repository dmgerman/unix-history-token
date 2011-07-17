begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ObjCRuntime.h - Objective C runtime features -----------*- C++ -*-===//
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
name|CLANG_DRIVER_OBJCRUNTIME_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_OBJCRUNTIME_H_
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|ObjCRuntime
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|GNU
block|,
name|NeXT
block|}
enum|;
name|private
label|:
name|unsigned
name|RuntimeKind
range|:
literal|1
decl_stmt|;
name|public
label|:
name|void
name|setKind
parameter_list|(
name|Kind
name|k
parameter_list|)
block|{
name|RuntimeKind
operator|=
name|k
expr_stmt|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|RuntimeKind
operator|)
return|;
block|}
comment|/// True if the runtime provides native ARC entrypoints.  ARC may
comment|/// still be usable without this if the tool-chain provides a
comment|/// statically-linked runtime support library.
name|unsigned
name|HasARC
range|:
literal|1
decl_stmt|;
comment|/// True if the runtime supports ARC zeroing __weak.
name|unsigned
name|HasWeak
range|:
literal|1
decl_stmt|;
comment|/// True if the runtime provides the following entrypoint:
comment|///   void objc_terminate(void);
comment|/// If available, this will be called instead of abort() when an
comment|/// exception is thrown out of an EH cleanup.
name|unsigned
name|HasTerminate
range|:
literal|1
decl_stmt|;
name|ObjCRuntime
argument_list|()
operator|:
name|RuntimeKind
argument_list|(
name|NeXT
argument_list|)
operator|,
name|HasARC
argument_list|(
name|false
argument_list|)
operator|,
name|HasWeak
argument_list|(
name|false
argument_list|)
operator|,
name|HasTerminate
argument_list|(
argument|false
argument_list|)
block|{}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

