begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//- Copyright (c) 2010 James Grenning and Contributed to Unity Project
end_comment

begin_comment
comment|/* ==========================================     Unity Project - A Test Framework for C     Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams     [Released under MIT License. Please refer to license.txt for details] ========================================== */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_FIXTURE_MALLOC_OVERRIDES_H_
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FIXTURE_MALLOC_OVERRIDES_H_
end_define

begin_define
define|#
directive|define
name|malloc
value|unity_malloc
end_define

begin_define
define|#
directive|define
name|calloc
value|unity_calloc
end_define

begin_define
define|#
directive|define
name|realloc
value|unity_realloc
end_define

begin_define
define|#
directive|define
name|free
value|unity_free
end_define

begin_function_decl
name|void
modifier|*
name|unity_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unity_calloc
parameter_list|(
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unity_realloc
parameter_list|(
name|void
modifier|*
name|oldMem
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unity_free
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNITY_FIXTURE_MALLOC_OVERRIDES_H_ */
end_comment

end_unit

