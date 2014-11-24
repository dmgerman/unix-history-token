begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Minimal declarations for CUDA support.  Testing purposes only. */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|__constant__
value|__attribute__((constant))
end_define

begin_define
define|#
directive|define
name|__device__
value|__attribute__((device))
end_define

begin_define
define|#
directive|define
name|__global__
value|__attribute__((global))
end_define

begin_define
define|#
directive|define
name|__host__
value|__attribute__((host))
end_define

begin_define
define|#
directive|define
name|__shared__
value|__attribute__((shared))
end_define

begin_define
define|#
directive|define
name|__launch_bounds__
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__((launch_bounds(__VA_ARGS__)))
end_define

begin_struct
struct|struct
name|dim3
block|{
name|unsigned
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
name|__host__
name|__device__
name|dim3
argument_list|(
argument|unsigned x
argument_list|,
argument|unsigned y =
literal|1
argument_list|,
argument|unsigned z =
literal|1
argument_list|)
block|:
name|x
argument_list|(
name|x
argument_list|)
operator|,
name|y
argument_list|(
name|y
argument_list|)
operator|,
name|z
argument_list|(
argument|z
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cudaStream
modifier|*
name|cudaStream_t
typedef|;
end_typedef

begin_function_decl
name|int
name|cudaConfigureCall
parameter_list|(
name|dim3
name|gridSize
parameter_list|,
name|dim3
name|blockSize
parameter_list|,
name|size_t
name|sharedSize
init|=
literal|0
parameter_list|,
name|cudaStream_t
name|stream
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

end_unit

