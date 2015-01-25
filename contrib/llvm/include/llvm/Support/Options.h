begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Options.h - Debug options support -----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file declares helper objects for defining debug options that can be
end_comment

begin_comment
comment|/// configured via the command line. The new API currently builds on the cl::opt
end_comment

begin_comment
comment|/// API, but does not require the use of static globals.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// With this API options are registered during initialization. For passes, this
end_comment

begin_comment
comment|/// happens during pass initialization. Passes with options will call a static
end_comment

begin_comment
comment|/// registerOptions method during initialization that registers options with the
end_comment

begin_comment
comment|/// OptionRegistry. An example implementation of registerOptions is:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// static void registerOptions() {
end_comment

begin_comment
comment|///   OptionRegistry::registerOption<bool, Scalarizer,
end_comment

begin_comment
comment|///&Scalarizer::ScalarizeLoadStore>(
end_comment

begin_comment
comment|///       "scalarize-load-store",
end_comment

begin_comment
comment|///       "Allow the scalarizer pass to scalarize loads and store", false);
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When reading data for options the interface is via the LLVMContext. Option
end_comment

begin_comment
comment|/// data for passes should be read from the context during doInitialization. An
end_comment

begin_comment
comment|/// example of reading the above option would be:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ScalarizeLoadStore =
end_comment

begin_comment
comment|///   M.getContext().getOption<bool,
end_comment

begin_comment
comment|///                            Scalarizer,
end_comment

begin_comment
comment|///&Scalarizer::ScalarizeLoadStore>();
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_OPTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|detail
block|{
comment|// Options are keyed of the unique address of a static character synthesized
comment|// based on template arguments.
name|template
operator|<
name|typename
name|ValT
operator|,
name|typename
name|Base
operator|,
name|ValT
argument_list|(
name|Base
operator|::
operator|*
name|Mem
argument_list|)
operator|>
name|class
name|OptionKey
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|ValT
operator|,
name|typename
name|Base
operator|,
name|ValT
argument_list|(
name|Base
operator|::
operator|*
name|Mem
argument_list|)
operator|>
name|char
name|OptionKey
operator|<
name|ValT
operator|,
name|Base
operator|,
name|Mem
operator|>
operator|::
name|ID
operator|=
literal|0
expr_stmt|;
block|}
comment|// namespace detail
comment|/// \brief Singleton class used to register debug options.
comment|///
comment|/// The OptionRegistry is responsible for managing lifetimes of the options and
comment|/// provides interfaces for option registration and reading values from options.
comment|/// This object is a singleton, only one instance should ever exist so that all
comment|/// options are registered in teh same place.
name|class
name|OptionRegistry
block|{
name|private
label|:
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|cl
operator|::
name|Option
operator|*
operator|>
name|Options
expr_stmt|;
comment|/// \brief Adds a cl::Option to the registry.
comment|///
comment|/// \param Key unique key for option
comment|/// \param O option to map to \p Key
comment|///
comment|/// Allocated cl::Options are owened by the OptionRegistry and are deallocated
comment|/// on destruction or removal
name|void
name|addOption
argument_list|(
name|void
operator|*
name|Key
argument_list|,
name|cl
operator|::
name|Option
operator|*
name|O
argument_list|)
decl_stmt|;
name|public
label|:
operator|~
name|OptionRegistry
argument_list|()
expr_stmt|;
name|OptionRegistry
argument_list|()
block|{}
comment|/// \brief Returns a reference to the singleton instance.
specifier|static
name|OptionRegistry
modifier|&
name|instance
parameter_list|()
function_decl|;
comment|/// \brief Registers an option with the OptionRegistry singleton.
comment|///
comment|/// \tparam ValT type of the option's data
comment|/// \tparam Base class used to key the option
comment|/// \tparam Mem member of \p Base used for keying the option
comment|///
comment|/// Options are keyed off the template parameters to generate unique static
comment|/// characters. The template parameters are (1) the type of the data the
comment|/// option stores (\p ValT), the class that will read the option (\p Base),
comment|/// and the memeber that the class will store the data into (\p Mem).
name|template
operator|<
name|typename
name|ValT
operator|,
name|typename
name|Base
operator|,
name|ValT
argument_list|(
name|Base
operator|::
operator|*
name|Mem
argument_list|)
operator|>
specifier|static
name|void
name|registerOption
argument_list|(
argument|const char *ArgStr
argument_list|,
argument|const char *Desc
argument_list|,
argument|const ValT&InitValue
argument_list|)
block|{
name|cl
operator|::
name|opt
operator|<
name|ValT
operator|>
operator|*
name|Option
operator|=
name|new
name|cl
operator|::
name|opt
operator|<
name|ValT
operator|>
operator|(
name|ArgStr
operator|,
name|cl
operator|::
name|desc
argument_list|(
name|Desc
argument_list|)
operator|,
name|cl
operator|::
name|Hidden
operator|,
name|cl
operator|::
name|init
argument_list|(
name|InitValue
argument_list|)
operator|)
block|;
name|instance
argument_list|()
operator|.
name|addOption
argument_list|(
operator|&
name|detail
operator|::
name|OptionKey
operator|<
name|ValT
argument_list|,
name|Base
argument_list|,
name|Mem
operator|>
operator|::
name|ID
argument_list|,
name|Option
argument_list|)
block|;   }
comment|/// \brief Returns the value of the option.
comment|///
comment|/// \tparam ValT type of the option's data
comment|/// \tparam Base class used to key the option
comment|/// \tparam Mem member of \p Base used for keying the option
comment|///
comment|/// Reads option values based on the key generated by the template parameters.
comment|/// Keying for get() is the same as keying for registerOption.
name|template
operator|<
name|typename
name|ValT
operator|,
name|typename
name|Base
operator|,
name|ValT
argument_list|(
name|Base
operator|::
operator|*
name|Mem
argument_list|)
operator|>
name|ValT
name|get
argument_list|()
specifier|const
block|{
name|auto
name|It
operator|=
name|Options
operator|.
name|find
argument_list|(
operator|&
name|detail
operator|::
name|OptionKey
operator|<
name|ValT
argument_list|,
name|Base
argument_list|,
name|Mem
operator|>
operator|::
name|ID
argument_list|)
block|;
name|assert
argument_list|(
name|It
operator|!=
name|Options
operator|.
name|end
argument_list|()
operator|&&
literal|"Option not in OptionRegistry"
argument_list|)
block|;
return|return
operator|*
operator|(
name|cl
operator|::
name|opt
operator|<
name|ValT
operator|>
operator|*
operator|)
name|It
operator|->
name|second
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

