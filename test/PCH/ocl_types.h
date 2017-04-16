begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Used with the ocl_types.cl test */
end_comment

begin_comment
comment|// image1d_t
end_comment

begin_typedef
typedef|typedef
name|image1d_t
name|img1d_t
typedef|;
end_typedef

begin_comment
comment|// image1d_array_t
end_comment

begin_typedef
typedef|typedef
name|image1d_array_t
name|img1darr_t
typedef|;
end_typedef

begin_comment
comment|// image1d_buffer_t
end_comment

begin_typedef
typedef|typedef
name|image1d_buffer_t
name|img1dbuff_t
typedef|;
end_typedef

begin_comment
comment|// image2d_t
end_comment

begin_typedef
typedef|typedef
name|image2d_t
name|img2d_t
typedef|;
end_typedef

begin_comment
comment|// image2d_array_t
end_comment

begin_typedef
typedef|typedef
name|image2d_array_t
name|img2darr_t
typedef|;
end_typedef

begin_comment
comment|// image3d_t
end_comment

begin_typedef
typedef|typedef
name|image3d_t
name|img3d_t
typedef|;
end_typedef

begin_comment
comment|// sampler_t
end_comment

begin_typedef
typedef|typedef
name|sampler_t
name|smp_t
typedef|;
end_typedef

begin_comment
comment|// event_t
end_comment

begin_typedef
typedef|typedef
name|event_t
name|evt_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__OPENCL_VERSION__
operator|>=
literal|200
end_if

begin_comment
comment|// clk_event_t
end_comment

begin_typedef
typedef|typedef
name|clk_event_t
name|clkevt_t
typedef|;
end_typedef

begin_comment
comment|// queue_t
end_comment

begin_typedef
typedef|typedef
name|queue_t
name|q_t
typedef|;
end_typedef

begin_comment
comment|// reserve_id_t
end_comment

begin_typedef
typedef|typedef
name|reserve_id_t
name|reserveid_t
typedef|;
end_typedef

begin_comment
comment|// image2d_depth_t
end_comment

begin_typedef
typedef|typedef
name|image2d_depth_t
name|img2ddep_t
typedef|;
end_typedef

begin_comment
comment|// image2d_array_depth_t
end_comment

begin_typedef
typedef|typedef
name|image2d_array_depth_t
name|img2darr_dep_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|OPENCL
name|EXTENSION
name|cl_khr_gl_msaa_sharing
name|:
name|enable
end_pragma

begin_comment
comment|// image2d_msaa_t
end_comment

begin_typedef
typedef|typedef
name|image2d_msaa_t
name|img2dmsaa_t
typedef|;
end_typedef

begin_comment
comment|// image2d_array_msaa_t
end_comment

begin_typedef
typedef|typedef
name|image2d_array_msaa_t
name|img2darrmsaa_t
typedef|;
end_typedef

begin_comment
comment|// image2d_msaa_depth_t
end_comment

begin_typedef
typedef|typedef
name|image2d_msaa_depth_t
name|img2dmsaadep_t
typedef|;
end_typedef

begin_comment
comment|// image2d_array_msaa_depth_t
end_comment

begin_typedef
typedef|typedef
name|image2d_array_msaa_depth_t
name|img2darrmsaadep_t
typedef|;
end_typedef

begin_comment
comment|// pipe specifier
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_person
block|{
name|int
name|id
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|Person
typedef|;
end_typedef

begin_function_decl
name|void
name|int_pipe_function
parameter_list|(
name|pipe
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|person_pipe_function
parameter_list|(
name|pipe
name|Person
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

