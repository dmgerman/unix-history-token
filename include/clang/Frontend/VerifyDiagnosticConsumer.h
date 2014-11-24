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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
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

begin_include
include|#
directive|include
file|<memory>
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
comment|/// \code
comment|///   expected-{error,warning,remark,note}
comment|/// \endcode
comment|///
comment|/// to tag if it's an expected error, remark or warning, and place the expected
comment|/// text between {{ and }} markers. The full text doesn't have to be included,
comment|/// only enough to ensure that the correct diagnostic was emitted.
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
comment|/// If the diagnostic is generated in a separate file, for example in a shared
comment|/// header file, it may be beneficial to be able to declare the file in which
comment|/// the diagnostic will appear, rather than placing the expected-* directive in
comment|/// the actual file itself.  This can be done using the following syntax:
comment|///
comment|/// \code
comment|///   // expected-error@path/include.h:15 {{error message}}
comment|/// \endcode
comment|///
comment|/// The path can be absolute or relative and the same search paths will be used
comment|/// as for #include directives.  The line number in an external file may be
comment|/// substituted with '*' meaning that any line number will match (useful where
comment|/// the included file is, for example, a system header where the actual line
comment|/// number may change and is not critical).
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
comment|/// Regex matching mode may be selected by appending '-re' to type and
comment|/// including regexes wrapped in double curly braces in the directive, such as:
comment|///
comment|/// \code
comment|///   expected-error-re {{format specifies type 'wchar_t **' (aka '{{.+}}')}}
comment|/// \endcode
comment|///
comment|/// Examples matching error: "variable has incomplete type 'struct s'"
comment|///
comment|/// \code
comment|///   // expected-error {{variable has incomplete type 'struct s'}}
comment|///   // expected-error {{variable has incomplete type}}
comment|///
comment|///   // expected-error-re {{variable has type 'struct {{.}}'}}
comment|///   // expected-error-re {{variable has type 'struct {{.*}}'}}
comment|///   // expected-error-re {{variable has type 'struct {{(.*)}}'}}
comment|///   // expected-error-re {{variable has type 'struct{{[[:space:]](.*)}}'}}
comment|/// \endcode
comment|///
comment|/// VerifyDiagnosticConsumer expects at least one expected-* directive to
comment|/// be found inside the source code.  If no diagnostics are expected the
comment|/// following directive can be used to indicate this:
comment|///
comment|/// \code
comment|///   // expected-no-diagnostics
comment|/// \endcode
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
name|bool
name|MatchAnyLine
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
name|bool
name|MatchAnyLine
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
argument|bool MatchAnyLine
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
name|Max
argument_list|)
operator|,
name|MatchAnyLine
argument_list|(
argument|MatchAnyLine
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
argument|const Directive&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|Directive
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
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
name|Remarks
decl_stmt|;
name|DirectiveList
name|Notes
decl_stmt|;
name|void
name|Reset
parameter_list|()
block|{
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Errors
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Warnings
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Remarks
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DeleteContainerPointers
argument_list|(
name|Notes
argument_list|)
expr_stmt|;
block|}
operator|~
name|ExpectedData
argument_list|()
block|{
name|Reset
argument_list|()
block|; }
block|}
struct|;
enum|enum
name|DirectiveStatus
block|{
name|HasNoDirectives
block|,
name|HasNoDirectivesReported
block|,
name|HasExpectedNoDiagnostics
block|,
name|HasOtherExpectedDirectives
block|}
enum|;
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
name|std
operator|::
name|unique_ptr
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
specifier|const
name|LangOptions
modifier|*
name|LangOpts
decl_stmt|;
name|SourceManager
modifier|*
name|SrcManager
decl_stmt|;
name|unsigned
name|ActiveSourceFiles
decl_stmt|;
name|DirectiveStatus
name|Status
decl_stmt|;
name|ExpectedData
name|ED
decl_stmt|;
name|void
name|CheckDiagnostics
parameter_list|()
function_decl|;
name|void
name|setSourceManager
parameter_list|(
name|SourceManager
modifier|&
name|SM
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|SrcManager
operator|||
name|SrcManager
operator|==
operator|&
name|SM
operator|)
operator|&&
literal|"SourceManager changed!"
argument_list|)
expr_stmt|;
name|SrcManager
operator|=
operator|&
name|SM
expr_stmt|;
block|}
comment|// These facilities are used for validation in debug builds.
name|class
name|UnparsedFileStatus
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|Data
expr_stmt|;
name|public
label|:
name|UnparsedFileStatus
argument_list|(
argument|const FileEntry *File
argument_list|,
argument|bool FoundDirectives
argument_list|)
block|:
name|Data
argument_list|(
argument|File
argument_list|,
argument|FoundDirectives
argument_list|)
block|{}
specifier|const
name|FileEntry
operator|*
name|getFile
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|bool
name|foundDirectives
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|.
name|getInt
argument_list|()
return|;
block|}
block|}
empty_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
specifier|const
name|FileEntry
operator|*
operator|>
name|ParsedFilesMap
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|UnparsedFileStatus
operator|>
name|UnparsedFilesMap
expr_stmt|;
name|ParsedFilesMap
name|ParsedFiles
decl_stmt|;
name|UnparsedFilesMap
name|UnparsedFiles
decl_stmt|;
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
name|void
name|BeginSourceFile
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
specifier|const
name|Preprocessor
operator|*
name|PP
argument_list|)
name|override
decl_stmt|;
name|void
name|EndSourceFile
argument_list|()
name|override
expr_stmt|;
enum|enum
name|ParsedStatus
block|{
comment|/// File has been processed via HandleComment.
name|IsParsed
block|,
comment|/// File has diagnostics and may have directives.
name|IsUnparsed
block|,
comment|/// File has diagnostics but guaranteed no directives.
name|IsUnparsedNoDirectives
block|}
enum|;
comment|/// \brief Update lists of parsed and unparsed files.
name|void
name|UpdateParsedFileStatus
parameter_list|(
name|SourceManager
modifier|&
name|SM
parameter_list|,
name|FileID
name|FID
parameter_list|,
name|ParsedStatus
name|PS
parameter_list|)
function_decl|;
name|bool
name|HandleComment
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|SourceRange
name|Comment
argument_list|)
name|override
decl_stmt|;
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
name|override
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

