begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PrettyPrinter.h - Classes for aiding with AST printing -*- C++ -*-===//
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
comment|//  This file defines the PrinterHelper interface.
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
name|LLVM_CLANG_AST_PRETTY_PRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_PRETTY_PRINTER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|PrinterHelper
block|{
name|public
label|:
name|virtual
operator|~
name|PrinterHelper
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|handledStmt
argument_list|(
name|Stmt
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Describes how types, statements, expressions, and
comment|/// declarations should be printed.
struct|struct
name|PrintingPolicy
block|{
comment|/// \brief Create a default printing policy for C.
name|PrintingPolicy
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LO
argument_list|)
operator|:
name|Indentation
argument_list|(
literal|2
argument_list|)
operator|,
name|LangOpts
argument_list|(
name|LO
argument_list|)
operator|,
name|SuppressSpecifiers
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressTag
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressTagKind
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressScope
argument_list|(
name|false
argument_list|)
operator|,
name|Dump
argument_list|(
name|false
argument_list|)
operator|,
name|ConstantArraySizeAsWritten
argument_list|(
argument|false
argument_list|)
block|{ }
comment|/// \brief The number of spaces to use to indent each line.
name|unsigned
name|Indentation
operator|:
literal|8
expr_stmt|;
comment|/// \brief What language we're printing.
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
comment|/// \brief Whether we should suppress printing of the actual specifiers for
comment|/// the given type or declaration.
comment|///
comment|/// This flag is only used when we are printing declarators beyond
comment|/// the first declarator within a declaration group. For example, given:
comment|///
comment|/// \code
comment|/// const int *x, *y;
comment|/// \endcode
comment|///
comment|/// SuppressSpecifiers will be false when printing the
comment|/// declaration for "x", so that we will print "int *x"; it will be
comment|/// \c true when we print "y", so that we suppress printing the
comment|/// "const int" type specifier and instead only print the "*y".
name|bool
name|SuppressSpecifiers
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether type printing should skip printing the actual tag type.
comment|///
comment|/// This is used when the caller needs to print a tag definition in front
comment|/// of the type, as in constructs like the following:
comment|///
comment|/// \code
comment|/// typedef struct { int x, y; } Point;
comment|/// \endcode
name|bool
name|SuppressTag
range|:
literal|1
decl_stmt|;
comment|/// \brief If we are printing a tag type, suppresses printing of the
comment|/// kind of tag, e.g., "struct", "union", "enum".
name|bool
name|SuppressTagKind
range|:
literal|1
decl_stmt|;
comment|/// \brief Suppresses printing of scope specifiers.
name|bool
name|SuppressScope
range|:
literal|1
decl_stmt|;
comment|/// \brief True when we are "dumping" rather than "pretty-printing",
comment|/// where dumping involves printing the internal details of the AST
comment|/// and pretty-printing involves printing something similar to
comment|/// source code.
name|bool
name|Dump
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we should print the sizes of constant array expressions
comment|/// as written in the sources.
comment|///
comment|/// This flag is determines whether arrays types declared as
comment|///
comment|/// \code
comment|/// int a[4+10*10];
comment|/// char a[] = "A string";
comment|/// \endcode
comment|///
comment|/// will be printed as written or as follows:
comment|///
comment|/// \code
comment|/// int a[104];
comment|/// char a[9] = "A string";
comment|/// \endcode
name|bool
name|ConstantArraySizeAsWritten
range|:
literal|1
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

