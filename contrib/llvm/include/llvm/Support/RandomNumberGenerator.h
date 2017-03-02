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

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|/// A random number generator.
comment|///
comment|/// Instances of this class should not be shared across threads. The
comment|/// seed should be set by passing the -rng-seed=<uint64> option. Use
comment|/// Module::createRNG to create a new RNG instance for use with that
comment|/// module.
name|class
name|RandomNumberGenerator
block|{
comment|// 64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
comment|// http://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
comment|// This RNG is deterministically portable across C++11
comment|// implementations.
name|using
name|generator_type
init|=
name|std
operator|::
name|mt19937_64
decl_stmt|;
name|public
label|:
name|using
name|result_type
init|=
name|generator_type
operator|::
name|result_type
decl_stmt|;
comment|/// Returns a random number in the range [0, Max).
name|result_type
name|operator
argument_list|()
argument_list|()
expr_stmt|;
specifier|static
name|constexpr
name|result_type
name|min
parameter_list|()
block|{
return|return
name|generator_type
operator|::
name|min
argument_list|()
return|;
block|}
specifier|static
name|constexpr
name|result_type
name|max
parameter_list|()
block|{
return|return
name|generator_type
operator|::
name|max
argument_list|()
return|;
block|}
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
name|generator_type
name|Generator
decl_stmt|;
comment|// Noncopyable.
name|RandomNumberGenerator
argument_list|(
specifier|const
name|RandomNumberGenerator
operator|&
name|other
argument_list|)
operator|=
name|delete
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
operator|=
name|delete
decl_stmt|;
name|friend
name|class
name|Module
decl_stmt|;
block|}
empty_stmt|;
comment|// Get random vector of specified size
name|std
operator|::
name|error_code
name|getRandomBytes
argument_list|(
argument|void *Buffer
argument_list|,
argument|size_t Size
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

