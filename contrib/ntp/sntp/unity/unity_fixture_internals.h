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
name|UNITY_FIXTURE_INTERNALS_H_
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FIXTURE_INTERNALS_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|_UNITY_FIXTURE_T
block|{
name|int
name|Verbose
decl_stmt|;
name|unsigned
name|int
name|RepeatCount
decl_stmt|;
specifier|const
name|char
modifier|*
name|NameFilter
decl_stmt|;
specifier|const
name|char
modifier|*
name|GroupFilter
decl_stmt|;
block|}
name|UNITY_FIXTURE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|unityfunction
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|UnityTestRunner
parameter_list|(
name|unityfunction
modifier|*
name|setup
parameter_list|,
name|unityfunction
modifier|*
name|body
parameter_list|,
name|unityfunction
modifier|*
name|teardown
parameter_list|,
specifier|const
name|char
modifier|*
name|printableName
parameter_list|,
specifier|const
name|char
modifier|*
name|group
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityIgnoreTest
parameter_list|(
specifier|const
name|char
modifier|*
name|printableName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityMalloc_StartTest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityMalloc_EndTest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|UnityFailureCount
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|UnityGetCommandLineOptions
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityConcludeFixtureTest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPointer_Set
parameter_list|(
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPointer_UndoAllSets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPointer_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualPointer
parameter_list|(
specifier|const
name|void
modifier|*
name|expected
parameter_list|,
specifier|const
name|void
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNITY_FIXTURE_INTERNALS_H_ */
end_comment

end_unit

