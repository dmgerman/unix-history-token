begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2016 Ismael Jimenez Martinez. All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Licensed under the Apache License, Version 2.0 (the "License");
end_comment

begin_comment
comment|// you may not use this file except in compliance with the License.
end_comment

begin_comment
comment|// You may obtain a copy of the License at
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     http://www.apache.org/licenses/LICENSE-2.0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Unless required by applicable law or agreed to in writing, software
end_comment

begin_comment
comment|// distributed under the License is distributed on an "AS IS" BASIS,
end_comment

begin_comment
comment|// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
end_comment

begin_comment
comment|// See the License for the specific language governing permissions and
end_comment

begin_comment
comment|// limitations under the License.
end_comment

begin_comment
comment|// Source project : https://github.com/ismaelJimenez/cpp.leastsq
end_comment

begin_comment
comment|// Adapted to be used with google benchmark
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPLEXITY_H_
end_ifndef

begin_define
define|#
directive|define
name|COMPLEXITY_H_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"benchmark/benchmark_api.h"
end_include

begin_include
include|#
directive|include
file|"benchmark/reporter.h"
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
comment|// Return a vector containing the mean and standard devation information for
comment|// the specified list of reports. If 'reports' contains less than two
comment|// non-errored runs an empty vector is returned
name|std
operator|::
name|vector
operator|<
name|BenchmarkReporter
operator|::
name|Run
operator|>
name|ComputeStats
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|BenchmarkReporter
operator|::
name|Run
operator|>
operator|&
name|reports
argument_list|)
expr_stmt|;
comment|// Return a vector containing the bigO and RMS information for the specified
comment|// list of reports. If 'reports.size()< 2' an empty vector is returned.
name|std
operator|::
name|vector
operator|<
name|BenchmarkReporter
operator|::
name|Run
operator|>
name|ComputeBigO
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|BenchmarkReporter
operator|::
name|Run
operator|>
operator|&
name|reports
argument_list|)
expr_stmt|;
comment|// This data structure will contain the result returned by MinimalLeastSq
comment|//   - coef        : Estimated coeficient for the high-order term as
comment|//                   interpolated from data.
comment|//   - rms         : Normalized Root Mean Squared Error.
comment|//   - complexity  : Scalability form (e.g. oN, oNLogN). In case a scalability
comment|//                   form has been provided to MinimalLeastSq this will return
comment|//                   the same value. In case BigO::oAuto has been selected, this
comment|//                   parameter will return the best fitting curve detected.
struct|struct
name|LeastSq
block|{
name|LeastSq
argument_list|()
operator|:
name|coef
argument_list|(
literal|0.0
argument_list|)
operator|,
name|rms
argument_list|(
literal|0.0
argument_list|)
operator|,
name|complexity
argument_list|(
argument|oNone
argument_list|)
block|{}
name|double
name|coef
expr_stmt|;
name|double
name|rms
decl_stmt|;
name|BigO
name|complexity
decl_stmt|;
block|}
struct|;
comment|// Function to return an string for the calculated complexity
name|std
operator|::
name|string
name|GetBigOString
argument_list|(
argument|BigO complexity
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// COMPLEXITY_H_
end_comment

end_unit

