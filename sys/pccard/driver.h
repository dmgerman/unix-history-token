begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * pccard driver interface.  * Bruce Evans, November 1995.  * This file is in the public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_DRIVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_DRIVER_H_
end_define

begin_struct_decl
struct_decl|struct
name|lkm_table
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pccard_device
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|pccard_add_driver
name|__P
argument_list|(
operator|(
expr|struct
name|pccard_device
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_I386_ISA_ISA_DEVICE_H_
end_ifdef

begin_comment
comment|/* XXX actually if inthand2_t is declared */
end_comment

begin_decl_stmt
name|int
name|pccard_alloc_intr
name|__P
argument_list|(
operator|(
name|u_int
name|imask
operator|,
name|inthand2_t
operator|*
name|hand
operator|,
name|int
name|unit
operator|,
name|u_int
operator|*
name|maskp
operator|,
name|u_int
operator|*
name|pcic_imask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|pccard_configure
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pccard_remove_driver
name|__P
argument_list|(
operator|(
expr|struct
name|pccard_device
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pcic_probe
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX should be linker set */
end_comment

begin_enum
enum|enum
name|beepstate
block|{
name|BEEP_ON
block|,
name|BEEP_OFF
block|}
enum|;
end_enum

begin_decl_stmt
name|void
name|pccard_insert_beep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pccard_remove_beep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pccard_success_beep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pccard_failure_beep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pccard_beep_select
name|__P
argument_list|(
operator|(
expr|enum
name|beepstate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCCARD_DRIVER_H_ */
end_comment

end_unit

