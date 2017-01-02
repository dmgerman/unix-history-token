begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_STAT_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_STAT_H_
end_define

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
name|template
operator|<
name|typename
name|VType
operator|,
name|typename
name|NumType
operator|>
name|class
name|Stat1
expr_stmt|;
name|template
operator|<
name|typename
name|VType
operator|,
name|typename
name|NumType
operator|>
name|class
name|Stat1MinMax
expr_stmt|;
typedef|typedef
name|Stat1
operator|<
name|float
operator|,
name|int64_t
operator|>
name|Stat1_f
expr_stmt|;
typedef|typedef
name|Stat1
operator|<
name|double
operator|,
name|int64_t
operator|>
name|Stat1_d
expr_stmt|;
typedef|typedef
name|Stat1MinMax
operator|<
name|float
operator|,
name|int64_t
operator|>
name|Stat1MinMax_f
expr_stmt|;
typedef|typedef
name|Stat1MinMax
operator|<
name|double
operator|,
name|int64_t
operator|>
name|Stat1MinMax_d
expr_stmt|;
name|template
operator|<
name|typename
name|VType
operator|>
name|class
name|Vector2
expr_stmt|;
name|template
operator|<
name|typename
name|VType
operator|>
name|class
name|Vector3
expr_stmt|;
name|template
operator|<
name|typename
name|VType
operator|>
name|class
name|Vector4
expr_stmt|;
name|template
operator|<
name|typename
name|VType
operator|,
name|typename
name|NumType
operator|>
name|class
name|Stat1
block|{
name|public
operator|:
typedef|typedef
name|Stat1
operator|<
name|VType
operator|,
name|NumType
operator|>
name|Self
expr_stmt|;
name|Stat1
argument_list|()
block|{
name|Clear
argument_list|()
block|; }
comment|// Create a sample of value dat and weight 1
name|explicit
name|Stat1
argument_list|(
argument|const VType&dat
argument_list|)
block|{
name|sum_
operator|=
name|dat
block|;
name|sum_squares_
operator|=
name|Sqr
argument_list|(
name|dat
argument_list|)
block|;
name|numsamples_
operator|=
literal|1
block|;   }
comment|// Create statistics for all the samples between begin (included)
comment|// and end(excluded)
name|explicit
name|Stat1
argument_list|(
argument|const VType *begin
argument_list|,
argument|const VType *end
argument_list|)
block|{
name|Clear
argument_list|()
block|;
for|for
control|(
specifier|const
name|VType
modifier|*
name|item
init|=
name|begin
init|;
name|item
operator|<
name|end
condition|;
operator|++
name|item
control|)
block|{
operator|(
operator|*
name|this
operator|)
operator|+=
name|Stat1
argument_list|(
operator|*
name|item
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Create a sample of value dat and weight w
name|Stat1
argument_list|(
argument|const VType&dat
argument_list|,
argument|const NumType&w
argument_list|)
block|{
name|sum_
operator|=
name|w
operator|*
name|dat
block|;
name|sum_squares_
operator|=
name|w
operator|*
name|Sqr
argument_list|(
name|dat
argument_list|)
block|;
name|numsamples_
operator|=
name|w
block|;   }
comment|// Copy operator
name|Stat1
argument_list|(
argument|const Self&stat
argument_list|)
block|{
name|sum_
operator|=
name|stat
operator|.
name|sum_
block|;
name|sum_squares_
operator|=
name|stat
operator|.
name|sum_squares_
block|;
name|numsamples_
operator|=
name|stat
operator|.
name|numsamples_
block|;   }
name|void
name|Clear
argument_list|()
block|{
name|numsamples_
operator|=
name|NumType
argument_list|()
block|;
name|sum_squares_
operator|=
name|sum_
operator|=
name|VType
argument_list|()
block|;   }
name|Self
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
block|{
name|sum_
operator|=
name|stat
operator|.
name|sum_
block|;
name|sum_squares_
operator|=
name|stat
operator|.
name|sum_squares_
block|;
name|numsamples_
operator|=
name|stat
operator|.
name|numsamples_
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|// Merge statistics from two sample sets.
name|Self
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
block|{
name|sum_
operator|+=
name|stat
operator|.
name|sum_
block|;
name|sum_squares_
operator|+=
name|stat
operator|.
name|sum_squares_
block|;
name|numsamples_
operator|+=
name|stat
operator|.
name|numsamples_
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|// The operation opposite to +=
name|Self
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
block|{
name|sum_
operator|-=
name|stat
operator|.
name|sum_
block|;
name|sum_squares_
operator|-=
name|stat
operator|.
name|sum_squares_
block|;
name|numsamples_
operator|-=
name|stat
operator|.
name|numsamples_
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|// Multiply the weight of the set of samples by a factor k
name|Self
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|VType
operator|&
name|k
operator|)
block|{
name|sum_
operator|*=
name|k
block|;
name|sum_squares_
operator|*=
name|k
block|;
name|numsamples_
operator|*=
name|k
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|// Merge statistics from two sample sets.
name|Self
name|operator
operator|+
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
specifier|const
block|{
return|return
name|Self
argument_list|(
operator|*
name|this
argument_list|)
operator|+=
name|stat
return|;
block|}
comment|// The operation opposite to +
name|Self
name|operator
operator|-
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
specifier|const
block|{
return|return
name|Self
argument_list|(
operator|*
name|this
argument_list|)
operator|-=
name|stat
return|;
block|}
comment|// Multiply the weight of the set of samples by a factor k
name|Self
name|operator
modifier|*
argument_list|(
specifier|const
name|VType
operator|&
name|k
argument_list|)
decl|const
block|{
return|return
name|Self
argument_list|(
operator|*
name|this
argument_list|)
operator|*=
name|k
return|;
block|}
comment|// Return the total weight of this sample set
name|NumType
name|numSamples
argument_list|()
specifier|const
block|{
return|return
name|numsamples_
return|;
block|}
comment|// Return the sum of this sample set
name|VType
name|Sum
argument_list|()
specifier|const
block|{
return|return
name|sum_
return|;
block|}
comment|// Return the mean of this sample set
name|VType
name|Mean
argument_list|()
specifier|const
block|{
if|if
condition|(
name|numsamples_
operator|==
literal|0
condition|)
return|return
name|VType
argument_list|()
return|;
return|return
name|sum_
operator|*
operator|(
literal|1.0
operator|/
name|numsamples_
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Return the mean of this sample set and compute the standard deviation at
end_comment

begin_comment
comment|// the same time.
end_comment

begin_decl_stmt
name|VType
name|Mean
argument_list|(
name|VType
operator|*
name|stddev
argument_list|)
decl|const
block|{
if|if
condition|(
name|numsamples_
operator|==
literal|0
condition|)
return|return
name|VType
argument_list|()
return|;
name|VType
name|mean
init|=
name|sum_
operator|*
operator|(
literal|1.0
operator|/
name|numsamples_
operator|)
decl_stmt|;
if|if
condition|(
name|stddev
condition|)
block|{
name|VType
name|avg_squares
init|=
name|sum_squares_
operator|*
operator|(
literal|1.0
operator|/
name|numsamples_
operator|)
decl_stmt|;
operator|*
name|stddev
operator|=
name|Sqrt
argument_list|(
name|avg_squares
operator|-
name|Sqr
argument_list|(
name|mean
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|mean
return|;
block|}
end_decl_stmt

begin_comment
comment|// Return the standard deviation of the sample set
end_comment

begin_expr_stmt
name|VType
name|StdDev
argument_list|()
specifier|const
block|{
if|if
condition|(
name|numsamples_
operator|==
literal|0
condition|)
return|return
name|VType
argument_list|()
return|;
name|VType
name|mean
operator|=
name|Mean
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|VType
name|avg_squares
init|=
name|sum_squares_
operator|*
operator|(
literal|1.0
operator|/
name|numsamples_
operator|)
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|Sqrt
argument_list|(
name|avg_squares
operator|-
name|Sqr
argument_list|(
name|mean
argument_list|)
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}   private:
name|static_assert
argument_list|(
name|std
operator|::
name|is_integral
operator|<
name|NumType
operator|>
operator|::
name|value
operator|&&
operator|!
name|std
operator|::
name|is_same
operator|<
name|NumType
argument_list|,
name|bool
operator|>
operator|::
name|value
argument_list|,
literal|"NumType must be an integral type that is not bool."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Let i be the index of the samples provided (using +=)
end_comment

begin_comment
comment|// and weight[i],value[i] be the data of sample #i
end_comment

begin_comment
comment|// then the variables have the following meaning:
end_comment

begin_decl_stmt
name|NumType
name|numsamples_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// sum of weight[i];
end_comment

begin_decl_stmt
name|VType
name|sum_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// sum of weight[i]*value[i];
end_comment

begin_decl_stmt
name|VType
name|sum_squares_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// sum of weight[i]*value[i]^2;
end_comment

begin_comment
comment|// Template function used to square a number.
end_comment

begin_comment
comment|// For a vector we square all components
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|SType
name|Sqr
argument_list|(
argument|const SType&dat
argument_list|)
block|{
return|return
name|dat
operator|*
name|dat
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|Vector2
operator|<
name|SType
operator|>
name|Sqr
argument_list|(
argument|const Vector2<SType>&dat
argument_list|)
block|{
return|return
name|dat
operator|.
name|MulComponents
argument_list|(
name|dat
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|Vector3
operator|<
name|SType
operator|>
name|Sqr
argument_list|(
argument|const Vector3<SType>&dat
argument_list|)
block|{
return|return
name|dat
operator|.
name|MulComponents
argument_list|(
name|dat
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|Vector4
operator|<
name|SType
operator|>
name|Sqr
argument_list|(
argument|const Vector4<SType>&dat
argument_list|)
block|{
return|return
name|dat
operator|.
name|MulComponents
argument_list|(
name|dat
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Template function used to take the square root of a number.
end_comment

begin_comment
comment|// For a vector we square all components
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|SType
name|Sqrt
argument_list|(
argument|const SType&dat
argument_list|)
block|{
comment|// Avoid NaN due to imprecision in the calculations
if|if
condition|(
name|dat
operator|<
literal|0
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|sqrt
argument_list|(
name|dat
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|Vector2
operator|<
name|SType
operator|>
name|Sqrt
argument_list|(
argument|const Vector2<SType>&dat
argument_list|)
block|{
comment|// Avoid NaN due to imprecision in the calculations
return|return
name|Max
argument_list|(
name|dat
argument_list|,
name|Vector2
operator|<
name|SType
operator|>
operator|(
operator|)
argument_list|)
operator|.
name|Sqrt
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|Vector3
operator|<
name|SType
operator|>
name|Sqrt
argument_list|(
argument|const Vector3<SType>&dat
argument_list|)
block|{
comment|// Avoid NaN due to imprecision in the calculations
return|return
name|Max
argument_list|(
name|dat
argument_list|,
name|Vector3
operator|<
name|SType
operator|>
operator|(
operator|)
argument_list|)
operator|.
name|Sqrt
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|SType
operator|>
specifier|static
specifier|inline
name|Vector4
operator|<
name|SType
operator|>
name|Sqrt
argument_list|(
argument|const Vector4<SType>&dat
argument_list|)
block|{
comment|// Avoid NaN due to imprecision in the calculations
return|return
name|Max
argument_list|(
name|dat
argument_list|,
name|Vector4
operator|<
name|SType
operator|>
operator|(
operator|)
argument_list|)
operator|.
name|Sqrt
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Useful printing function
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|VType
operator|,
name|typename
name|NumType
operator|>
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|out
operator|,
specifier|const
name|Stat1
operator|<
name|VType
operator|,
name|NumType
operator|>
operator|&
name|s
operator|)
block|{
name|out
operator|<<
literal|"{ avg = "
operator|<<
name|s
operator|.
name|Mean
argument_list|()
operator|<<
literal|" std = "
operator|<<
name|s
operator|.
name|StdDev
argument_list|()
operator|<<
literal|" nsamples = "
operator|<<
name|s
operator|.
name|NumSamples
argument_list|()
operator|<<
literal|"}"
block|;
return|return
name|out
return|;
block|}
end_expr_stmt

begin_comment
comment|// Stat1MinMax: same as Stat1, but it also
end_comment

begin_comment
comment|// keeps the Min and Max values; the "-"
end_comment

begin_comment
comment|// operator is disabled because it cannot be implemented
end_comment

begin_comment
comment|// efficiently
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|VType
operator|,
name|typename
name|NumType
operator|>
name|class
name|Stat1MinMax
operator|:
name|public
name|Stat1
operator|<
name|VType
operator|,
name|NumType
operator|>
block|{
name|public
operator|:
typedef|typedef
name|Stat1MinMax
operator|<
name|VType
operator|,
name|NumType
operator|>
name|Self
expr_stmt|;
name|Stat1MinMax
argument_list|()
block|{
name|Clear
argument_list|()
block|; }
comment|// Create a sample of value dat and weight 1
name|explicit
name|Stat1MinMax
argument_list|(
specifier|const
name|VType
operator|&
name|dat
argument_list|)
operator|:
name|Stat1
operator|<
name|VType
operator|,
name|NumType
operator|>
operator|(
name|dat
operator|)
block|{
name|max_
operator|=
name|dat
block|;
name|min_
operator|=
name|dat
block|;   }
comment|// Create statistics for all the samples between begin (included)
comment|// and end(excluded)
name|explicit
name|Stat1MinMax
argument_list|(
argument|const VType *begin
argument_list|,
argument|const VType *end
argument_list|)
block|{
name|Clear
argument_list|()
block|;
for|for
control|(
specifier|const
name|VType
modifier|*
name|item
init|=
name|begin
init|;
name|item
operator|<
name|end
condition|;
operator|++
name|item
control|)
block|{
operator|(
operator|*
name|this
operator|)
operator|+=
name|Stat1MinMax
argument_list|(
operator|*
name|item
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Create a sample of value dat and weight w
end_comment

begin_expr_stmt
unit|Stat1MinMax
operator|(
specifier|const
name|VType
operator|&
name|dat
operator|,
specifier|const
name|NumType
operator|&
name|w
operator|)
operator|:
name|Stat1
operator|<
name|VType
operator|,
name|NumType
operator|>
operator|(
name|dat
operator|,
name|w
operator|)
block|{
name|max_
operator|=
name|dat
block|;
name|min_
operator|=
name|dat
block|;   }
comment|// Copy operator
name|Stat1MinMax
argument_list|(
specifier|const
name|Self
operator|&
name|stat
argument_list|)
operator|:
name|Stat1
operator|<
name|VType
operator|,
name|NumType
operator|>
operator|(
name|stat
operator|)
block|{
name|max_
operator|=
name|stat
operator|.
name|max_
block|;
name|min_
operator|=
name|stat
operator|.
name|min_
block|;   }
name|void
name|Clear
argument_list|()
block|{
name|Stat1
operator|<
name|VType
block|,
name|NumType
operator|>
operator|::
name|Clear
argument_list|()
block|;
if|if
condition|(
name|std
operator|::
name|numeric_limits
operator|<
name|VType
operator|>
operator|::
name|has_infinity
condition|)
block|{
name|min_
operator|=
name|std
operator|::
name|numeric_limits
operator|<
name|VType
operator|>
operator|::
name|infinity
argument_list|()
expr_stmt|;
name|max_
operator|=
operator|-
name|std
operator|::
name|numeric_limits
operator|<
name|VType
operator|>
operator|::
name|infinity
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|min_
operator|=
name|std
operator|::
name|numeric_limits
operator|<
name|VType
operator|>
operator|::
name|max
argument_list|()
expr_stmt|;
name|max_
operator|=
name|std
operator|::
name|numeric_limits
operator|<
name|VType
operator|>
operator|::
name|min
argument_list|()
expr_stmt|;
block|}
end_else

begin_expr_stmt
unit|}    Self
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
block|{
name|this
operator|->
name|Stat1
operator|<
name|VType
block|,
name|NumType
operator|>
operator|::
name|operator
operator|=
operator|(
name|stat
operator|)
block|;
name|max_
operator|=
name|stat
operator|.
name|max_
block|;
name|min_
operator|=
name|stat
operator|.
name|min_
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Merge statistics from two sample sets.
end_comment

begin_expr_stmt
name|Self
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
block|{
name|this
operator|->
name|Stat1
operator|<
name|VType
block|,
name|NumType
operator|>
operator|::
name|operator
operator|+=
operator|(
name|stat
operator|)
block|;
if|if
condition|(
name|stat
operator|.
name|max_
operator|>
name|max_
condition|)
name|max_
operator|=
name|stat
operator|.
name|max_
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|stat
operator|.
name|min_
operator|<
name|min_
condition|)
name|min_
operator|=
name|stat
operator|.
name|min_
expr_stmt|;
end_if

begin_return
return|return
operator|(
operator|*
name|this
operator|)
return|;
end_return

begin_comment
unit|}
comment|// Multiply the weight of the set of samples by a factor k
end_comment

begin_expr_stmt
unit|Self
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|VType
operator|&
name|stat
operator|)
block|{
name|this
operator|->
name|Stat1
operator|<
name|VType
block|,
name|NumType
operator|>
operator|::
name|operator
operator|*=
operator|(
name|stat
operator|)
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Merge statistics from two sample sets.
end_comment

begin_expr_stmt
name|Self
name|operator
operator|+
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
specifier|const
block|{
return|return
name|Self
argument_list|(
operator|*
name|this
argument_list|)
operator|+=
name|stat
return|;
block|}
end_expr_stmt

begin_comment
comment|// Multiply the weight of the set of samples by a factor k
end_comment

begin_decl_stmt
name|Self
name|operator
modifier|*
argument_list|(
specifier|const
name|VType
operator|&
name|k
argument_list|)
decl|const
block|{
return|return
name|Self
argument_list|(
operator|*
name|this
argument_list|)
operator|*=
name|k
return|;
block|}
end_decl_stmt

begin_comment
comment|// Return the maximal value in this sample set
end_comment

begin_expr_stmt
name|VType
name|Max
argument_list|()
specifier|const
block|{
return|return
name|max_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return the minimal value in this sample set
end_comment

begin_expr_stmt
name|VType
name|Min
argument_list|()
specifier|const
block|{
return|return
name|min_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// The - operation makes no sense with Min/Max
end_comment

begin_comment
comment|// unless we keep the full list of values (but we don't)
end_comment

begin_comment
comment|// make it private, and let it undefined so nobody can call it
end_comment

begin_expr_stmt
name|Self
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// senseless. let it undefined.
end_comment

begin_comment
comment|// The operation opposite to -
end_comment

begin_expr_stmt
name|Self
name|operator
operator|-
operator|(
specifier|const
name|Self
operator|&
name|stat
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// senseless. let it undefined.
end_comment

begin_comment
comment|// Let i be the index of the samples provided (using +=)
end_comment

begin_comment
comment|// and weight[i],value[i] be the data of sample #i
end_comment

begin_comment
comment|// then the variables have the following meaning:
end_comment

begin_decl_stmt
name|VType
name|max_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// max of value[i]
end_comment

begin_decl_stmt
name|VType
name|min_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// min of value[i]
end_comment

begin_comment
unit|};
comment|// Useful printing function
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|VType
operator|,
name|typename
name|NumType
operator|>
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|out
operator|,
specifier|const
name|Stat1MinMax
operator|<
name|VType
operator|,
name|NumType
operator|>
operator|&
name|s
operator|)
block|{
name|out
operator|<<
literal|"{ avg = "
operator|<<
name|s
operator|.
name|Mean
argument_list|()
operator|<<
literal|" std = "
operator|<<
name|s
operator|.
name|StdDev
argument_list|()
operator|<<
literal|" nsamples = "
operator|<<
name|s
operator|.
name|NumSamples
argument_list|()
operator|<<
literal|" min = "
operator|<<
name|s
operator|.
name|Min
argument_list|()
operator|<<
literal|" max = "
operator|<<
name|s
operator|.
name|Max
argument_list|()
operator|<<
literal|"}"
block|;
return|return
name|out
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_STAT_H_
end_comment

end_unit

