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

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TagDecl
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
parameter_list|(
name|Stmt
modifier|*
name|E
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
init|=
literal|0
function_decl|;
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
name|LangOpts
argument_list|(
name|LO
argument_list|)
operator|,
name|Indentation
argument_list|(
literal|2
argument_list|)
operator|,
name|SuppressSpecifiers
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressTagKeyword
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressTag
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressScope
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressUnwrittenScope
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressInitializers
argument_list|(
name|false
argument_list|)
operator|,
name|ConstantArraySizeAsWritten
argument_list|(
name|false
argument_list|)
operator|,
name|AnonymousTagLocations
argument_list|(
name|true
argument_list|)
operator|,
name|SuppressStrongLifetime
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressLifetimeQualifiers
argument_list|(
name|false
argument_list|)
operator|,
name|Bool
argument_list|(
name|LO
operator|.
name|Bool
argument_list|)
operator|,
name|TerseOutput
argument_list|(
name|false
argument_list|)
operator|,
name|PolishForDeclaration
argument_list|(
name|false
argument_list|)
operator|,
name|MSWChar
argument_list|(
argument|LO.MicrosoftExt&& !LO.WChar
argument_list|)
block|{ }
comment|/// \brief What language we're printing.
name|LangOptions
name|LangOpts
expr_stmt|;
comment|/// \brief The number of spaces to use to indent each line.
name|unsigned
name|Indentation
range|:
literal|8
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
comment|/// \brief Whether type printing should skip printing the tag keyword.
comment|///
comment|/// This is used when printing the inner type of elaborated types,
comment|/// (as the tag keyword is part of the elaborated type):
comment|///
comment|/// \code
comment|/// struct Geometry::Point;
comment|/// \endcode
name|bool
name|SuppressTagKeyword
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
comment|/// \brief Suppresses printing of scope specifiers.
name|bool
name|SuppressScope
range|:
literal|1
decl_stmt|;
comment|/// \brief Suppress printing parts of scope specifiers that don't need
comment|/// to be written, e.g., for inline or anonymous namespaces.
name|bool
name|SuppressUnwrittenScope
range|:
literal|1
decl_stmt|;
comment|/// \brief Suppress printing of variable initializers.
comment|///
comment|/// This flag is used when printing the loop variable in a for-range
comment|/// statement. For example, given:
comment|///
comment|/// \code
comment|/// for (auto x : coll)
comment|/// \endcode
comment|///
comment|/// SuppressInitializers will be true when printing "auto x", so that the
comment|/// internal initializer constructed for x will not be printed.
name|bool
name|SuppressInitializers
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
comment|/// \brief When printing an anonymous tag name, also print the location of
comment|/// that entity (e.g., "enum<anonymous at t.h:10:5>"). Otherwise, just
comment|/// prints "<anonymous>" for the name.
name|bool
name|AnonymousTagLocations
range|:
literal|1
decl_stmt|;
comment|/// \brief When true, suppress printing of the __strong lifetime qualifier in
comment|/// ARC.
name|unsigned
name|SuppressStrongLifetime
range|:
literal|1
decl_stmt|;
comment|/// \brief When true, suppress printing of lifetime qualifier in
comment|/// ARC.
name|unsigned
name|SuppressLifetimeQualifiers
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we can use 'bool' rather than '_Bool', even if the language
comment|/// doesn't actually have 'bool' (because, e.g., it is defined as a macro).
name|unsigned
name|Bool
range|:
literal|1
decl_stmt|;
comment|/// \brief Provide a 'terse' output.
comment|///
comment|/// For example, in this mode we don't print function bodies, class members,
comment|/// declarations inside namespaces etc.  Effectively, this should print
comment|/// only the requested declaration.
name|unsigned
name|TerseOutput
range|:
literal|1
decl_stmt|;
comment|/// \brief When true, do certain refinement needed for producing proper
comment|/// declaration tag; such as, do not print attributes attached to the declaration.
comment|///
name|unsigned
name|PolishForDeclaration
range|:
literal|1
decl_stmt|;
comment|/// \brief When true, print the built-in wchar_t type as __wchar_t. For use in
comment|/// Microsoft mode when wchar_t is not available.
name|unsigned
name|MSWChar
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

