begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Dirk Grunwald (grunwald@cs.uiuc.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SampleHistogram_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SampleHistogram_h
value|1
end_define

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_include
include|#
directive|include
file|<SmplStat.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|SampleHistogramMinimum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|SampleHistogramMaximum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|SampleHistogram
range|:
name|public
name|SampleStatistic
block|{
name|protected
operator|:
name|short
name|howManyBuckets
block|;
name|int
operator|*
name|bucketCount
block|;
name|double
operator|*
name|bucketLimit
block|;
name|public
operator|:
name|SampleHistogram
argument_list|(
argument|double low
argument_list|,
argument|double hi
argument_list|,
argument|double bucketWidth = -
literal|1.0
argument_list|)
block|;
operator|~
name|SampleHistogram
argument_list|()
block|;
name|virtual
name|void
name|reset
argument_list|()
block|;
name|virtual
name|void
name|operator
operator|+=
operator|(
name|double
operator|)
block|;
name|int
name|similarSamples
argument_list|(
name|double
argument_list|)
block|;
name|int
name|buckets
argument_list|()
block|;
name|double
name|bucketThreshold
argument_list|(
argument|int i
argument_list|)
block|;
name|int
name|inBucket
argument_list|(
argument|int i
argument_list|)
block|;
name|void
name|printBuckets
argument_list|(
name|ostream
operator|&
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|int
name|SampleHistogram
operator|::
name|buckets
argument_list|()
block|{
return|return
operator|(
name|howManyBuckets
operator|)
return|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|double
name|SampleHistogram
operator|::
name|bucketThreshold
argument_list|(
argument|int i
argument_list|)
block|{
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|howManyBuckets
condition|)
name|error
argument_list|(
literal|"invalid bucket access"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|bucketLimit
index|[
name|i
index|]
operator|)
return|;
end_return

begin_expr_stmt
unit|}  inline
name|int
name|SampleHistogram
operator|::
name|inBucket
argument_list|(
argument|int i
argument_list|)
block|{
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|howManyBuckets
condition|)
name|error
argument_list|(
literal|"invalid bucket access"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|bucketCount
index|[
name|i
index|]
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

