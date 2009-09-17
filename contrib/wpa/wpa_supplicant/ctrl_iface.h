begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / UNIX domain socket -based control interface  * Copyright (c) 2004-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTRL_IFACE_H
end_ifndef

begin_define
define|#
directive|define
name|CTRL_IFACE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE
end_ifdef

begin_comment
comment|/* Shared functions from ctrl_iface.c; to be called by ctrl_iface backends */
end_comment

begin_comment
comment|/**  * wpa_supplicant_ctrl_iface_process - Process ctrl_iface command  * @wpa_s: Pointer to wpa_supplicant data  * @buf: Received command buffer (nul terminated string)  * @resp_len: Variable to be set to the response length  * Returns: Response (*resp_len bytes) or %NULL on failure  *  * Control interface backends call this function when receiving a message that  * they do not process internally, i.e., anything else than ATTACH, DETACH,  * and LEVEL. The return response value is then sent to the external program  * that sent the command. Caller is responsible for freeing the buffer after  * this. If %NULL is returned, *resp_len can be set to two special values:  * 1 = send "FAIL\n" response, 2 = send "OK\n" response. If *resp_len has any  * other value, no response is sent.  */
end_comment

begin_function_decl
name|char
modifier|*
name|wpa_supplicant_ctrl_iface_process
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_supplicant_ctrl_iface_process - Process global ctrl_iface command  * @global: Pointer to global data from wpa_supplicant_init()  * @buf: Received command buffer (nul terminated string)  * @resp_len: Variable to be set to the response length  * Returns: Response (*resp_len bytes) or %NULL on failure  *  * Control interface backends call this function when receiving a message from  * the global ctrl_iface connection. The return response value is then sent to  * the external program that sent the command. Caller is responsible for  * freeing the buffer after this. If %NULL is returned, *resp_len can be set to  * two special values: 1 = send "FAIL\n" response, 2 = send "OK\n" response. If  * *resp_len has any other value, no response is sent.  */
end_comment

begin_function_decl
name|char
modifier|*
name|wpa_supplicant_global_ctrl_iface_process
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions that each ctrl_iface backend must implement */
end_comment

begin_comment
comment|/**  * wpa_supplicant_ctrl_iface_init - Initialize control interface  * @wpa_s: Pointer to wpa_supplicant data  * Returns: Pointer to private data on success, %NULL on failure  *  * Initialize the control interface and start receiving commands from external  * programs.  *  * Required to be implemented in each control interface backend.  */
end_comment

begin_function_decl
name|struct
name|ctrl_iface_priv
modifier|*
name|wpa_supplicant_ctrl_iface_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_supplicant_ctrl_iface_deinit - Deinitialize control interface  * @priv: Pointer to private data from wpa_supplicant_ctrl_iface_init()  *  * Deinitialize the control interface that was initialized with  * wpa_supplicant_ctrl_iface_init().  *  * Required to be implemented in each control interface backend.  */
end_comment

begin_function_decl
name|void
name|wpa_supplicant_ctrl_iface_deinit
parameter_list|(
name|struct
name|ctrl_iface_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_supplicant_ctrl_iface_wait - Wait for ctrl_iface monitor  * @priv: Pointer to private data from wpa_supplicant_ctrl_iface_init()  *  * Wait until the first message from an external program using the control  * interface is received. This function can be used to delay normal startup  * processing to allow control interface programs to attach with  * %wpa_supplicant before normal operations are started.  *  * Required to be implemented in each control interface backend.  */
end_comment

begin_function_decl
name|void
name|wpa_supplicant_ctrl_iface_wait
parameter_list|(
name|struct
name|ctrl_iface_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_supplicant_global_ctrl_iface_init - Initialize global control interface  * @global: Pointer to global data from wpa_supplicant_init()  * Returns: Pointer to private data on success, %NULL on failure  *  * Initialize the global control interface and start receiving commands from  * external programs.  *  * Required to be implemented in each control interface backend.  */
end_comment

begin_function_decl
name|struct
name|ctrl_iface_global_priv
modifier|*
name|wpa_supplicant_global_ctrl_iface_init
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_supplicant_global_ctrl_iface_deinit - Deinitialize global ctrl interface  * @priv: Pointer to private data from wpa_supplicant_global_ctrl_iface_init()  *  * Deinitialize the global control interface that was initialized with  * wpa_supplicant_global_ctrl_iface_init().  *  * Required to be implemented in each control interface backend.  */
end_comment

begin_function_decl
name|void
name|wpa_supplicant_global_ctrl_iface_deinit
parameter_list|(
name|struct
name|ctrl_iface_global_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_CTRL_IFACE */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|ctrl_iface_priv
modifier|*
name|wpa_supplicant_ctrl_iface_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_ctrl_iface_deinit
parameter_list|(
name|struct
name|ctrl_iface_priv
modifier|*
name|priv
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_ctrl_iface_send
parameter_list|(
name|struct
name|ctrl_iface_priv
modifier|*
name|priv
parameter_list|,
name|int
name|level
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_ctrl_iface_wait
parameter_list|(
name|struct
name|ctrl_iface_priv
modifier|*
name|priv
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|ctrl_iface_global_priv
modifier|*
name|wpa_supplicant_global_ctrl_iface_init
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_global_ctrl_iface_deinit
parameter_list|(
name|struct
name|ctrl_iface_global_priv
modifier|*
name|priv
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_H */
end_comment

end_unit

