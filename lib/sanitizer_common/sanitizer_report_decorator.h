begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_report_decorator.h ----------------------------*- C++ -*-===//
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
comment|// Tags to decorate the sanitizer reports.
end_comment

begin_comment
comment|// Currently supported tags:
end_comment

begin_comment
comment|//   * None.
end_comment

begin_comment
comment|//   * ANSI color sequences.
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
name|SANITIZER_REPORT_DECORATOR_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_REPORT_DECORATOR_H
end_define

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|class
name|AnsiColorDecorator
block|{
name|public
label|:
name|explicit
name|AnsiColorDecorator
argument_list|(
argument|bool use_ansi_colors
argument_list|)
block|:
name|ansi_
argument_list|(
argument|use_ansi_colors
argument_list|)
block|{ }
specifier|const
name|char
operator|*
name|Bold
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Black
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[30m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Red
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[31m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Green
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[32m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Yellow
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[33m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Blue
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[34m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Magenta
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[35m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Cyan
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[36m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|White
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[37m"
operator|:
literal|""
return|;
block|}
specifier|const
name|char
operator|*
name|Default
argument_list|()
specifier|const
block|{
return|return
name|ansi_
operator|?
literal|"\033[1m\033[0m"
operator|:
literal|""
return|;
block|}
name|private
label|:
name|bool
name|ansi_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_REPORT_DECORATOR_H
end_comment

end_unit

