begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Dirk Grunwald (grunwald@cs.uiuc.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACG_h
end_ifndef

begin_define
define|#
directive|define
name|_ACG_h
value|1
end_define

begin_include
include|#
directive|include
file|<RNG.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|//	Additive number generator. This method is presented in Volume II
end_comment

begin_comment
comment|//	of The Art of Computer Programming by Knuth. I've coded the algorithm
end_comment

begin_comment
comment|//	and have added the extensions by Andres Nowatzyk of CMU to randomize
end_comment

begin_comment
comment|//	the result of algorithm M a bit	by using an LCG& a spatial
end_comment

begin_comment
comment|//	permutation table.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//	The version presented uses the same constants for the LCG that Andres
end_comment

begin_comment
comment|//	uses (chosen by trial& error). The spatial permutation table is
end_comment

begin_comment
comment|//	the same size (it's based on word size). This is for 32-bit words.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//	The ``auxillary table'' used by the LCG table varies in size, and
end_comment

begin_comment
comment|//	is chosen to be the the smallest power of two which is larger than
end_comment

begin_comment
comment|//	twice the size of the state table.
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|ACG
range|:
name|public
name|RNG
block|{
name|unsigned
name|long
name|initialSeed
block|;
comment|// used to reset generator
name|int
name|initialTableEntry
block|;
name|unsigned
name|long
operator|*
name|state
block|;
name|unsigned
name|long
operator|*
name|auxState
block|;
name|short
name|stateSize
block|;
name|short
name|auxSize
block|;
name|unsigned
name|long
name|lcgRecurr
block|;
name|short
name|j
block|;
name|short
name|k
block|;
name|protected
operator|:
name|public
operator|:
name|ACG
argument_list|(
argument|unsigned long seed =
literal|0
argument_list|,
argument|int size =
literal|55
argument_list|)
block|;
name|virtual
operator|~
name|ACG
argument_list|()
block|;
comment|//
comment|// Return a long-words word of random bits
comment|//
name|virtual
name|unsigned
name|long
name|asLong
argument_list|()
block|;
name|virtual
name|void
name|reset
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

