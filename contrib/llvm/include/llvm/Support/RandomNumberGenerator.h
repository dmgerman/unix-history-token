begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/Support/RandomNumberGenerator.h - RNG for diversity ---*- C++ -*-==//
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
comment|// This file defines an abstraction for random number generation (RNG).
end_comment

begin_comment
comment|// Note that the current implementation is not cryptographically secure
end_comment

begin_comment
comment|// as it uses the C++11<random> facilities.
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
name|LLVM_SUPPORT_RANDOMNUMBERGENERATOR_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RANDOMNUMBERGENERATOR_H_
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_comment
comment|// Needed for uint64_t on Windows.
end_comment

begin_include
include|#
directive|include
file|<random>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A random number generator.
comment|/// Instances of this class should not be shared across threads.
name|class
name|RandomNumberGenerator
block|{
name|public
label|:
comment|/// Seeds and salts the underlying RNG engine. The salt of type StringRef
comment|/// is passed into the constructor. The seed can be set on the command
comment|/// line via -rng-seed=<uint64>.
comment|/// The reason for the salt is to ensure different random streams even if
comment|/// the same seed is used for multiple invocations of the compiler.
comment|/// A good salt value should add additional entropy and be constant across
comment|/// different machines (i.e., no paths) to allow for reproducible builds.
comment|/// An instance of this class can be retrieved from the current Module.
comment|/// \see Module::getRNG
name|RandomNumberGenerator
argument_list|(
argument|StringRef Salt
argument_list|)
empty_stmt|;
comment|/// Returns a random number in the range [0, Max).
name|uint64_t
name|next
parameter_list|(
name|uint64_t
name|Max
parameter_list|)
function_decl|;
name|private
label|:
comment|// 64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
comment|// http://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
name|std
operator|::
name|mt19937_64
name|Generator
expr_stmt|;
comment|// Noncopyable.
name|RandomNumberGenerator
argument_list|(
argument|const RandomNumberGenerator&other
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|RandomNumberGenerator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RandomNumberGenerator
operator|&
name|other
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

