begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2015 Google Inc. All rights reserved.
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

begin_include
include|#
directive|include
file|"benchmark/benchmark_api.h"
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
comment|// these counter-related functions are hidden to reduce API surface.
name|namespace
name|internal
block|{
name|void
name|Finish
parameter_list|(
name|UserCounters
modifier|*
name|l
parameter_list|,
name|double
name|time
parameter_list|,
name|double
name|num_threads
parameter_list|)
function_decl|;
name|void
name|Increment
parameter_list|(
name|UserCounters
modifier|*
name|l
parameter_list|,
name|UserCounters
specifier|const
modifier|&
name|r
parameter_list|)
function_decl|;
name|bool
name|SameNames
parameter_list|(
name|UserCounters
specifier|const
modifier|&
name|l
parameter_list|,
name|UserCounters
specifier|const
modifier|&
name|r
parameter_list|)
function_decl|;
block|}
comment|// end namespace internal
block|}
end_decl_stmt

begin_comment
comment|//end namespace benchmark
end_comment

end_unit

