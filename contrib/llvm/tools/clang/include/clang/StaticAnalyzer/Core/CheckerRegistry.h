begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CheckerRegistry.h - Maintains all available checkers ---*- C++ -*-===//
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
name|LLVM_CLANG_STATICANALYZER_CORE_CHECKERREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_CHECKERREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/CheckerManager.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// FIXME: move this information to an HTML file in docs/.
end_comment

begin_comment
comment|// At the very least, a checker plugin is a dynamic library that exports
end_comment

begin_comment
comment|// clang_analyzerAPIVersionString. This should be defined as follows:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   extern "C"
end_comment

begin_comment
comment|//   const char clang_analyzerAPIVersionString[] =
end_comment

begin_comment
comment|//     CLANG_ANALYZER_API_VERSION_STRING;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is used to check whether the current version of the analyzer is known to
end_comment

begin_comment
comment|// be incompatible with a plugin. Plugins with incompatible version strings,
end_comment

begin_comment
comment|// or without a version string at all, will not be loaded.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To add a custom checker to the analyzer, the plugin must also define the
end_comment

begin_comment
comment|// function clang_registerCheckers. For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    extern "C"
end_comment

begin_comment
comment|//    void clang_registerCheckers (CheckerRegistry&registry) {
end_comment

begin_comment
comment|//      registry.addChecker<MainCallChecker>("example.MainCallChecker",
end_comment

begin_comment
comment|//        "Disallows calls to functions called main");
end_comment

begin_comment
comment|//    }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The first method argument is the full name of the checker, including its
end_comment

begin_comment
comment|// enclosing package. By convention, the registered name of a checker is the
end_comment

begin_comment
comment|// name of the associated class (the template argument).
end_comment

begin_comment
comment|// The second method argument is a short human-readable description of the
end_comment

begin_comment
comment|// checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The clang_registerCheckers function may add any number of checkers to the
end_comment

begin_comment
comment|// registry. If any checkers require additional initialization, use the three-
end_comment

begin_comment
comment|// argument form of CheckerRegistry::addChecker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To load a checker plugin, specify the full path to the dynamic library as
end_comment

begin_comment
comment|// the argument to the -load option in the cc1 frontend. You can then enable
end_comment

begin_comment
comment|// your custom checker using the -analyzer-checker:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   clang -cc1 -load</path/to/plugin.dylib> -analyze
end_comment

begin_comment
comment|//     -analyzer-checker=<example.MainCallChecker>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For a complete working example, see examples/analyzer-plugin.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_ANALYZER_API_VERSION_STRING
end_ifndef

begin_comment
comment|// FIXME: The Clang version string is not particularly granular;
end_comment

begin_comment
comment|// the analyzer infrastructure can change a lot between releases.
end_comment

begin_comment
comment|// Unfortunately, this string has to be statically embedded in each plugin,
end_comment

begin_comment
comment|// so we can't just use the functions defined in Version.h.
end_comment

begin_include
include|#
directive|include
file|"clang/Basic/Version.h"
end_include

begin_define
define|#
directive|define
name|CLANG_ANALYZER_API_VERSION_STRING
value|CLANG_VERSION_STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|CheckerOptInfo
decl_stmt|;
comment|/// Manages a set of available checkers for running a static analysis.
comment|/// The checkers are organized into packages by full name, where including
comment|/// a package will recursively include all subpackages and checkers within it.
comment|/// For example, the checker "core.builtin.NoReturnFunctionChecker" will be
comment|/// included if initializeManager() is called with an option of "core",
comment|/// "core.builtin", or the full name "core.builtin.NoReturnFunctionChecker".
name|class
name|CheckerRegistry
block|{
name|public
label|:
comment|/// Initialization functions perform any necessary setup for a checker.
comment|/// They should include a call to CheckerManager::registerChecker.
typedef|typedef
name|void
function_decl|(
modifier|*
name|InitializationFunction
function_decl|)
parameter_list|(
name|CheckerManager
modifier|&
parameter_list|)
function_decl|;
struct|struct
name|CheckerInfo
block|{
name|InitializationFunction
name|Initialize
decl_stmt|;
name|StringRef
name|FullName
decl_stmt|;
name|StringRef
name|Desc
decl_stmt|;
name|CheckerInfo
argument_list|(
argument|InitializationFunction fn
argument_list|,
argument|StringRef name
argument_list|,
argument|StringRef desc
argument_list|)
block|:
name|Initialize
argument_list|(
name|fn
argument_list|)
operator|,
name|FullName
argument_list|(
name|name
argument_list|)
operator|,
name|Desc
argument_list|(
argument|desc
argument_list|)
block|{}
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CheckerInfo
operator|>
name|CheckerInfoList
expr_stmt|;
name|private
label|:
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|initializeManager
argument_list|(
argument|CheckerManager&mgr
argument_list|)
block|{
name|mgr
operator|.
name|registerChecker
operator|<
name|T
operator|>
operator|(
operator|)
block|;   }
name|public
operator|:
comment|/// Adds a checker to the registry. Use this non-templated overload when your
comment|/// checker requires custom initialization.
name|void
name|addChecker
argument_list|(
argument|InitializationFunction fn
argument_list|,
argument|StringRef fullName
argument_list|,
argument|StringRef desc
argument_list|)
expr_stmt|;
comment|/// Adds a checker to the registry. Use this templated overload when your
comment|/// checker does not require any custom initialization.
name|template
operator|<
name|class
name|T
operator|>
name|void
name|addChecker
argument_list|(
argument|StringRef fullName
argument_list|,
argument|StringRef desc
argument_list|)
block|{
comment|// Avoid MSVC's Compiler Error C2276:
comment|// http://msdn.microsoft.com/en-us/library/850cstw1(v=VS.80).aspx
name|addChecker
argument_list|(
operator|&
name|CheckerRegistry
operator|::
name|initializeManager
operator|<
name|T
operator|>
argument_list|,
name|fullName
argument_list|,
name|desc
argument_list|)
block|;   }
comment|/// Initializes a CheckerManager by calling the initialization functions for
comment|/// all checkers specified by the given CheckerOptInfo list. The order of this
comment|/// list is significant; later options can be used to reverse earlier ones.
comment|/// This can be used to exclude certain checkers in an included package.
name|void
name|initializeManager
argument_list|(
argument|CheckerManager&mgr
argument_list|,
argument|SmallVectorImpl<CheckerOptInfo>&opts
argument_list|)
specifier|const
expr_stmt|;
comment|/// Prints the name and description of all checkers in this registry.
comment|/// This output is not intended to be machine-parseable.
name|void
name|printHelp
argument_list|(
name|raw_ostream
operator|&
name|out
argument_list|,
name|size_t
name|maxNameChars
operator|=
literal|30
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|mutable
name|CheckerInfoList
name|Checkers
decl_stmt|;
name|mutable
name|llvm
operator|::
name|StringMap
operator|<
name|size_t
operator|>
name|Packages
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace ento
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

