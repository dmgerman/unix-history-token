begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tdfx_pci.h -- Prototypes for tdfx device methods */
end_comment

begin_comment
comment|/* Copyright (C) 2000 by Coleman Kane<cokane@pohl.ececs.uc.edu>*/
end_comment

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_comment
comment|/* Driver functions */
end_comment

begin_function_decl
specifier|static
name|int
name|tdfx_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_setmtrr
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_clrmtrr
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CDEV file ops */
end_comment

begin_decl_stmt
specifier|static
name|d_open_t
name|tdfx_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|tdfx_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_mmap_t
name|tdfx_mmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|tdfx_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Card Queries */
end_comment

begin_function_decl
specifier|static
name|int
name|tdfx_do_query
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_query_boards
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_query_fetch
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_query_update
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Card PIO funcs */
end_comment

begin_function_decl
specifier|static
name|int
name|tdfx_do_pio
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_do_pio_wt
parameter_list|(
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_do_pio_rd
parameter_list|(
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

end_unit

