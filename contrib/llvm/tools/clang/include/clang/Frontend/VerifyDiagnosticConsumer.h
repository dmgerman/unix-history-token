begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- VerifyDiagnosticConsumer.h - Verifying Diagnostic Client -*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_VERIFYDIAGNOSTICSCLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_VERIFYDIAGNOSTICSCLIENT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Preprocessor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|TextDiagnosticBuffer
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
comment|/// VerifyDiagnosticConsumer - Create a diagnostic client which will use
comment|/// markers in the input source to check that all the emitted diagnostics match
comment|/// those expected.
comment|///
comment|/// USING THE DIAGNOSTIC CHECKER:
comment|///
comment|/// Indicating that a line expects an error or a warning is simple. Put a
comment|/// comment on the line that has the diagnostic, use:
comment|///
comment|///     expected-{error,warning,note}
comment|///
comment|/// to tag if it's an expected error or warning, and place the expected text
comment|/// between {{ and }} markers. The full text doesn't have to be included, only
comment|/// enough to ensure that the correct diagnostic was emitted.
comment|///
comment|/// Here's an example:
comment|///
comment|/// \code
comment|///   int A = B; // expected-error {{use of undeclared identifier 'B'}}
comment|/// \endcode
comment|///
comment|/// You can place as many diagnostics on one line as you wish. To make the code
comment|/// more readable, you can use slash-newline to separate out the diagnostics.
comment|///
comment|/// Alternatively, it is possible to specify the line on which the diagnostic
comment|/// should appear by appending "@<line>" to "expected-<type>", for example:
comment|///
comment|/// \code
comment|///   #warning some text
comment|///   // expected-warning@10 {{some text}}
comment|/// \endcode
comment|///
comment|/// The line number may be absolute (as above), or relative to the current
comment|/// line by prefixing the number with either '+' or '-'.
comment|///
comment|/// The simple syntax above allows each specification to match exactly one
comment|/// error.  You can use the extended syntax to customize this. The extended
comment|/// syntax is "expected-<type><n> {{diag text}}", where \<type> is one of
comment|/// "error", "warning" or "note", and \<n> is a positive integer. This allows
comment|/// the diagnostic to appear as many times as specified. Example:
comment|///
comment|/// \code
comment|///   void f(); // expected-note 2 {{previous declaration is here}}
comment|/// \endcode
comment|///
comment|/// Where the diagnostic is expected to occur a minimum number of times, this
comment|/// can be specified by appending a '+' to the number. Example:
comment|///
comment|/// \code
comment|///   void f(); // expected-note 0+ {{previous declaration is here}}
comment|///   void g(); // expected-note 1+ {{previous declaration is here}}
comment|/// \endcode
comment|///
comment|/// In the first example, the diagnostic becomes optional, i.e. it will be
comment|/// swallowed if it occurs, but will not generate an error if it does not
comment|/// occur.  In the second example, the diagnostic must occur at least once.
comment|/// As a short-hand, "one or more" can be specified simply by '+'. Example:
comment|///
comment|/// \code
comment|///   void g(); // expected-note + {{previous declaration is here}}
comment|/// \endcode
comment|///
comment|/// A range can also be specified by "<n>-<m>".  Example:
comment|///
comment|/// \code
comment|///   void f(); // expected-note 0-1 {{previous declaration is here}}
comment|/// \endcode
comment|///
comment|/// In this example, the diagnostic may appear only once, if at all.
comment|///
comment|/// Regex matching mode may be selected by appending '-re' to type. Example:
comment|///
comment|///   expected-error-re
comment|///
comment|/// Examples matching error: "variable has incomplete type 'struct s'"
comment|///
comment|///   // expected-error {{variable has incomplete type 'struct s'}}
comment|///   // expected-error {{variable has incomplete type}}
comment|///
comment|///   // expected-error-re {{variable has has type 'struct .'}}
comment|///   // expected-error-re {{variable has has type 'struct .*'}}
comment|///   // expected-error-re {{variable has has type 'struct (.*)'}}
comment|///   // expected-error-re {{variable has has type 'struct[[:space:]](.*)'}}
comment|///
name|class
name|VerifyDiagnosticConsumer
range|:
name|public
name|DiagnosticConsumer
decl_stmt|,
name|public
name|CommentHandler
block|{
name|public
label|:
comment|/// Directive - Abstract class representing a parsed verify directive.
comment|///
name|class
name|Directive
block|{
name|public
label|:
specifier|static
name|Directive
modifier|*
name|create
parameter_list|(
name|bool
name|RegexKind
parameter_list|,
name|SourceLocation
name|DirectiveLoc
parameter_list|,
name|SourceLocation
name|DiagnosticLoc
parameter_list|,
name|StringRef
name|Text
parameter_list|,
name|unsigned
name|Min
parameter_list|,
name|unsigned
name|Max
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Constant representing n or more matches.
specifier|static
specifier|const
name|unsigned
name|MaxCount
init|=
name|UINT_MAX
decl_stmt|;
name|SourceLocation
name|DirectiveLoc
decl_stmt|;
name|SourceLocation
name|DiagnosticLoc
decl_stmt|;
specifier|const
name|std
operator|::
name|string
name|Text
expr_stmt|;
name|unsigned
name|Min
decl_stmt|,
name|Max
decl_stmt|;
name|virtual
operator|~
name|Directive
argument_list|()
block|{ }
comment|// Returns true if directive text is valid.
comment|// Otherwise returns false and populates E.
name|virtual
name|bool
name|isValid
argument_list|(
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|// Returns true on match.
name|virtual
name|bool
name|match
parameter_list|(
name|StringRef
name|S
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
name|Directive
argument_list|(
argument|SourceLocation DirectiveLoc
argument_list|,
argument|SourceLocation DiagnosticLoc
argument_list|,
argument|StringRef Text
argument_list|,
argument|unsigned Min
argument_list|,
argument|unsigned Max
argument_list|)
block|:
name|DirectiveLoc
argument_list|(
name|DirectiveLoc
argument_list|)
operator|,
name|DiagnosticLoc
argument_list|(
name|DiagnosticLoc
argument_list|)
operator|,
name|Text
argument_list|(
name|Text
argument_list|)
operator|,
name|Min
argument_list|(
name|Min
argument_list|)
operator|,
name|Max
argument_list|(
argument|Max
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|DirectiveLoc
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"DirectiveLoc is invalid!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|DiagnosticLoc
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"DiagnosticLoc is invalid!"
argument_list|)
block|;     }
name|private
operator|:
name|Directive
argument_list|(
specifier|const
name|Directive
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|Directive
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Directive
operator|*
operator|>
name|DirectiveList
expr_stmt|;
comment|/// ExpectedData - owns directive objects and deletes on destructor.
comment|///
struct|struct
name|ExpectedData
block|{
name|DirectiveList
name|Errors
decl_stmt|;
name|DirectiveList
name|Warnings
decl_stmt|;
name|DirectiveList
name|Notes
decl_stmt|;
operator|~
name|ExpectedData
argument_list|()
block|{
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Errors
argument_list|)
block|;
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Warnings
argument_list|)
block|;
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Notes
argument_list|)
block|;     }
block|}
struct|;
ifndef|#
directive|ifndef
name|NDEBUG
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
name|FileID
operator|>
name|FilesWithDiagnosticsSet
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
literal|4
operator|>
name|FilesParsedForDirectivesSet
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
name|DiagnosticConsumer
modifier|*
name|PrimaryClient
decl_stmt|;
name|bool
name|OwnsPrimaryClient
decl_stmt|;
name|OwningPtr
operator|<
name|TextDiagnosticBuffer
operator|>
name|Buffer
expr_stmt|;
specifier|const
name|Preprocessor
modifier|*
name|CurrentPreprocessor
decl_stmt|;
name|unsigned
name|ActiveSourceFiles
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|FilesWithDiagnosticsSet
name|FilesWithDiagnostics
decl_stmt|;
name|FilesParsedForDirectivesSet
name|FilesParsedForDirectives
decl_stmt|;
endif|#
directive|endif
name|ExpectedData
name|ED
decl_stmt|;
name|void
name|CheckDiagnostics
parameter_list|()
function_decl|;
name|public
label|:
comment|/// Create a new verifying diagnostic client, which will issue errors to
comment|/// the currently-attached diagnostic client when a diagnostic does not match
comment|/// what is expected (as indicated in the source file).
name|VerifyDiagnosticConsumer
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
expr_stmt|;
operator|~
name|VerifyDiagnosticConsumer
argument_list|()
expr_stmt|;
name|virtual
name|void
name|BeginSourceFile
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
specifier|const
name|Preprocessor
modifier|*
name|PP
parameter_list|)
function_decl|;
name|virtual
name|void
name|EndSourceFile
parameter_list|()
function_decl|;
comment|/// \brief Manually register a file as parsed.
specifier|inline
name|void
name|appendParsedFile
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|FilesParsedForDirectives
operator|.
name|insert
argument_list|(
name|File
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|virtual
name|bool
name|HandleComment
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|SourceRange
name|Comment
parameter_list|)
function_decl|;
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
name|DiagnosticsEngine
operator|::
name|Level
name|DiagLevel
argument_list|,
specifier|const
name|Diagnostic
operator|&
name|Info
argument_list|)
decl_stmt|;
name|virtual
name|DiagnosticConsumer
modifier|*
name|clone
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namspace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

