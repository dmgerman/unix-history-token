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
comment|// This file defines an abstraction for deterministic random number
end_comment

begin_comment
comment|// generation (RNG).  Note that the current implementation is not
end_comment

begin_comment
comment|// cryptographically secure as it uses the C++11<random> facilities.
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
comment|///
comment|/// Instances of this class should not be shared across threads. The
comment|/// seed should be set by passing the -rng-seed=<uint64> option. Use
comment|/// Module::createRNG to create a new RNG instance for use with that
comment|/// module.
name|class
name|RandomNumberGenerator
block|{
name|public
label|:
comment|/// Returns a random number in the range [0, Max).
name|uint_fast64_t
name|operator
argument_list|()
argument_list|()
expr_stmt|;
name|private
label|:
comment|/// Seeds and salts the underlying RNG engine.
comment|///
comment|/// This constructor should not be used directly. Instead use
comment|/// Module::createRNG to create a new RNG salted with the Module ID.
name|RandomNumberGenerator
argument_list|(
argument|StringRef Salt
argument_list|)
empty_stmt|;
comment|// 64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
comment|// http://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
comment|// This RNG is deterministically portable across C++11
comment|// implementations.
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
name|friend
name|class
name|Module
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

