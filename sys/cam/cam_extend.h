begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_EXTEND_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_EXTEND_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|extend_array
struct_decl|;
end_struct_decl

begin_function_decl
name|void
modifier|*
name|cam_extend_get
parameter_list|(
name|struct
name|extend_array
modifier|*
name|ea
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|extend_array
modifier|*
name|cam_extend_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|cam_extend_set
parameter_list|(
name|struct
name|extend_array
modifier|*
name|ea
parameter_list|,
name|int
name|index
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_extend_release
parameter_list|(
name|struct
name|extend_array
modifier|*
name|ea
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_EXTEND_H */
end_comment

end_unit

