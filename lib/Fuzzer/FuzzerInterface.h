begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerInterface.h - Interface header for the Fuzzer ------*- C++ -* ===//
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
comment|// Define the interface between the Fuzzer and the library being tested.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// WARNING: keep the interface free of STL or any other header-based C++ lib,
end_comment

begin_comment
comment|// to avoid bad interactions between the code used in the fuzzer and
end_comment

begin_comment
comment|// the code used in the target function.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|fuzzer
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|UserCallback
function_decl|)
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
comment|/** Simple C-like interface with a single user-supplied callback.  Usage:  #\code #include "FuzzerInterface.h"  void LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {   DoStuffWithData(Data, Size); }  // Implement your own main() or use the one from FuzzerMain.cpp. int main(int argc, char **argv) {   InitializeMeIfNeeded();   return fuzzer::FuzzerDriver(argc, argv, LLVMFuzzerTestOneInput); } #\endcode */
name|int
name|FuzzerDriver
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|UserCallback
name|Callback
parameter_list|)
function_decl|;
comment|/** An abstract class that allows to use user-supplied mutators with libFuzzer.  Usage:  #\code #include "FuzzerInterface.h" class MyFuzzer : public fuzzer::UserSuppliedFuzzer {  public:   // Must define the target function.   void TargetFunction(...) { ... }   // Optionally define the mutator.   size_t Mutate(...) { ... }   // Optionally define the CrossOver method.   size_t CrossOver(...) { ... } };  int main(int argc, char **argv) {   MyFuzzer F;   fuzzer::FuzzerDriver(argc, argv, F); } #\endcode */
name|class
name|UserSuppliedFuzzer
block|{
name|public
label|:
comment|/// Executes the target function on 'Size' bytes of 'Data'.
name|virtual
name|void
name|TargetFunction
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Mutates 'Size' bytes of data in 'Data' inplace into up to 'MaxSize' bytes,
comment|/// returns the new size of the data, which should be positive.
name|virtual
name|size_t
name|Mutate
parameter_list|(
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|,
name|size_t
name|MaxSize
parameter_list|)
block|{
return|return
name|BasicMutate
argument_list|(
name|Data
argument_list|,
name|Size
argument_list|,
name|MaxSize
argument_list|)
return|;
block|}
comment|/// Crosses 'Data1' and 'Data2', writes up to 'MaxOutSize' bytes into Out,
comment|/// returns the number of bytes written, which should be positive.
name|virtual
name|size_t
name|CrossOver
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data1
parameter_list|,
name|size_t
name|Size1
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|Data2
parameter_list|,
name|size_t
name|Size2
parameter_list|,
name|uint8_t
modifier|*
name|Out
parameter_list|,
name|size_t
name|MaxOutSize
parameter_list|)
block|{
return|return
name|BasicCrossOver
argument_list|(
name|Data1
argument_list|,
name|Size1
argument_list|,
name|Data2
argument_list|,
name|Size2
argument_list|,
name|Out
argument_list|,
name|MaxOutSize
argument_list|)
return|;
block|}
name|virtual
operator|~
name|UserSuppliedFuzzer
argument_list|()
block|{}
name|protected
operator|:
comment|/// These can be called internally by Mutate and CrossOver.
name|size_t
name|BasicMutate
argument_list|(
argument|uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|,
argument|size_t MaxSize
argument_list|)
expr_stmt|;
name|size_t
name|BasicCrossOver
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data1
parameter_list|,
name|size_t
name|Size1
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|Data2
parameter_list|,
name|size_t
name|Size2
parameter_list|,
name|uint8_t
modifier|*
name|Out
parameter_list|,
name|size_t
name|MaxOutSize
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Runs the fuzzing with the UserSuppliedFuzzer.
name|int
name|FuzzerDriver
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|UserSuppliedFuzzer
modifier|&
name|USF
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_INTERFACE_H
end_comment

end_unit

