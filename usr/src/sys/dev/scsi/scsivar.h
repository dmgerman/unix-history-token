begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)scsivar.h	5.3 (Berkeley) %G%  *  * from: $Header: scsivar.h,v 1.7 92/12/02 03:54:05 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI variables.  *  * Each SCSI Host Bus Adapter (hba) has:  *	a target queue head and tail  *	eight targets (for units to enqueue on)  *	a list of all units on all targets  *	its target number (the number cpu uses in initiating requests)  *	a driver  * Each SCSI target has:  *	a forward link so that it can sit on a SCSI host bus adapter queue  *	a unit queue head and tail  * Each SCSI unit has:  *	a forward link so that it can sit on a SCSI target queue  *	a driver  *	an hba& driver (so that we need not chase parent pointers)  */
end_comment

begin_comment
comment|/*  * Downcalls.  These are usually made from hba to unit, but can be  * hba->target->unit (when there are multiple units on a target).  */
end_comment

begin_comment
comment|/* device go function (`you got bus') */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*scdgo_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|scsi_cdb
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* intr function (`you no got bus no more') */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*scintr_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
name|int
name|stat
operator|,
name|int
name|resid
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/*  * Upcalls.  These are usually made from unit to hba, but can be  * unit->target->hba.  */
end_comment

begin_comment
comment|/* bus alloc function (`please get me bus') */
end_comment

begin_struct_decl
struct_decl|struct
name|sq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*scstart_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|sq
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|,
name|scdgo_fn
operator|,
expr|struct
name|device
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* bus go function (`I have bus and I set up cmd, so start it up') */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*scbusgo_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
name|int
name|targ
operator|,
name|scintr_fn
operator|,
expr|struct
name|device
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|,
name|int
name|pad
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* bus release function (`I have bus but do not need it after all') */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*scbusrel_fn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/*  * SCSI Queue.  This is an element in a queue of devices (targets  * and/or units) waiting for the bus.  */
end_comment

begin_struct
struct|struct
name|sq
block|{
name|struct
name|sq
modifier|*
name|sq_forw
decl_stmt|;
comment|/* forward link */
name|struct
name|buf
modifier|*
name|sq_bp
decl_stmt|;
comment|/* buffer for transfer */
name|scdgo_fn
name|sq_dgo
decl_stmt|;
comment|/* device-go to call when got bus */
name|struct
name|device
modifier|*
name|sq_dev
decl_stmt|;
comment|/* device argument to sq_dgo */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hba_softc
block|{
name|struct
name|device
name|hba_dev
decl_stmt|;
comment|/* generic part */
name|struct
name|sq
modifier|*
name|hba_head
decl_stmt|,
modifier|*
name|hba_tail
decl_stmt|;
comment|/* io queue (u's/t's wanting bus) */
name|char
name|hba_busy
decl_stmt|;
comment|/* true => will inspect qhead later */
name|struct
name|targ
modifier|*
name|hba_targets
index|[
literal|8
index|]
decl_stmt|;
comment|/* the 8 possible targets */
name|struct
name|hbadriver
modifier|*
name|hba_driver
decl_stmt|;
comment|/* hba driver */
name|scintr_fn
name|hba_intr
decl_stmt|;
comment|/* current interrupt function */
name|struct
name|device
modifier|*
name|hba_intrdev
decl_stmt|;
comment|/* arg 0 for hba_intr */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|targ
block|{
name|struct
name|device
name|t_dev
decl_stmt|;
comment|/* generic part */
name|struct
name|sq
name|t_forw
decl_stmt|;
comment|/* forward link, etc, on hba queue */
name|struct
name|sq
modifier|*
name|t_head
decl_stmt|,
modifier|*
name|t_tail
decl_stmt|;
comment|/* io queue */
name|char
name|t_busy
decl_stmt|;
comment|/* true => will inspect qhead later */
name|char
name|t_targ
decl_stmt|;
comment|/* target number */
name|char
name|t_nunits
decl_stmt|;
comment|/* count of live units */
name|char
name|t_firstunit
decl_stmt|;
comment|/* the first live unit */
name|struct
name|unit
modifier|*
name|t_units
index|[
literal|8
index|]
decl_stmt|;
comment|/* the 8 possible units */
name|scintr_fn
name|t_intr
decl_stmt|;
comment|/* current interrupt function */
name|struct
name|device
modifier|*
name|t_intrdev
decl_stmt|;
comment|/* arg 0 for t_intr */
block|}
struct|;
end_struct

begin_comment
comment|/* since a unit may be a disk, tape, etc., it has only pointer to dev */
end_comment

begin_struct
struct|struct
name|unit
block|{
name|struct
name|device
modifier|*
name|u_dev
decl_stmt|;
comment|/* backpointer to generic */
name|int
name|u_unit
decl_stmt|;
comment|/* unit number on target */
name|scstart_fn
name|u_start
decl_stmt|;
comment|/* upcall to get bus */
name|scbusgo_fn
name|u_go
decl_stmt|;
comment|/* upcall to use bus */
name|scbusrel_fn
name|u_rel
decl_stmt|;
comment|/* upcall to release bus early */
name|struct
name|device
modifier|*
name|u_updev
decl_stmt|;
comment|/* device for upcalls */
name|struct
name|sq
name|u_forw
decl_stmt|;
comment|/* forward link on target or hba q */
name|struct
name|unitdriver
modifier|*
name|u_driver
decl_stmt|;
comment|/* unit driver */
comment|/* the following three fields are copied from target& hba, for quick lookup */
name|int
name|u_targ
decl_stmt|;
comment|/* target number */
name|struct
name|hba_softc
modifier|*
name|u_hba
decl_stmt|;
comment|/* hba, from parent */
name|struct
name|hbadriver
modifier|*
name|u_hbd
decl_stmt|;
comment|/* hba driver, from parent */
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI hba driver.  */
end_comment

begin_struct
struct|struct
name|hbadriver
block|{
comment|/* immediate command; should not depend on receiving interrupts */
name|int
argument_list|(
argument|*hd_icmd
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|,
name|int
name|targ
operator|,
expr|struct
name|scsi_cdb
operator|*
name|cmd
operator|,
name|caddr_t
name|addr
operator|,
name|int
name|len
operator|,
name|int
name|rw
operator|)
argument_list|)
expr_stmt|;
comment|/* crash dump: like icmd(B_WRITE), but possibly from physmem */
name|int
argument_list|(
argument|*hd_dump
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|,
name|int
name|targ
operator|,
expr|struct
name|scsi_cdb
operator|*
name|cmd
operator|,
name|caddr_t
name|addr
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
name|scstart_fn
name|hd_start
decl_stmt|;
comment|/* allocate DMA& bus */
name|scbusgo_fn
name|hd_go
decl_stmt|;
comment|/* start DMA xfer on bus */
name|scbusrel_fn
name|hd_rel
decl_stmt|;
comment|/* release bus early */
name|void
argument_list|(
argument|*hd_reset
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI unit driver (`downcalls' from hba to unit).  */
end_comment

begin_struct
struct|struct
name|unitdriver
block|{
name|void
argument_list|(
argument|*ud_reset
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|unit
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* SCSI bus reset */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The generic SCSI target probe code passes the following to  * unit configuration `match' routines.  */
end_comment

begin_struct
struct|struct
name|scsi_attach_args
block|{
name|int
name|sa_targ
decl_stmt|;
comment|/* target number */
name|int
name|sa_unit
decl_stmt|;
comment|/* unit number */
name|int
name|sa_req_status
decl_stmt|;
comment|/* status from REQUEST SENSE */
name|struct
name|scsi_sense
name|sa_sn
decl_stmt|;
comment|/* contents from same */
name|int
name|sa_inq_status
decl_stmt|;
comment|/* status from INQUIRY command */
name|struct
name|scsi_inquiry
name|sa_si
decl_stmt|;
comment|/* contents from same */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The SCSICMDLEN macro gives the SCSI-standard-defined length of  * a given SCSI command.  This is 0 if the command is in an undefined  * group (see scsi.h).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|scsicmdlen
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SCSICMDLEN
parameter_list|(
name|cmd
parameter_list|)
value|scsicmdlen[(cmd)>> 5]
end_define

begin_comment
comment|/*  * The SCSIMSGLEN macro gives the SCSI-standard-defined length of  * a given SCSI message byte.  This is -1 if the message byte is  * undefined, -3 if it is an identify, -2 for an extended message,  * 0 if it is normal completion, otherwise positive.  */
end_comment

begin_define
define|#
directive|define
name|SMLEN_IDENTIFY
value|-3
end_define

begin_define
define|#
directive|define
name|SMLEN_EXTENDED
value|-2
end_define

begin_define
define|#
directive|define
name|SMLEN_UNDEF
value|-1
end_define

begin_define
define|#
directive|define
name|SMLEN_DONE
value|0
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|signed
name|char
name|scsimsglen
index|[
literal|0x24
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SCSIMSGLEN
parameter_list|(
name|msg
parameter_list|)
value|((msg)& MSG_IDENTIFY ? SMLEN_IDENTIFY : \ 			 (msg)> 0x24 ? SMLEN_UNDEF : scsimsglen[msg])
end_define

begin_comment
comment|/*  * Declarations for exported functions in scsi_subr.c  */
end_comment

begin_decl_stmt
name|int
name|scsi_test_unit_ready
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|,
name|int
name|targ
operator|,
name|int
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsi_request_sense
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_hbaattach
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_establish
name|__P
argument_list|(
operator|(
expr|struct
name|unit
operator|*
operator|,
expr|struct
name|device
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_printinq
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_inquiry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_inq_ansi
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_inq_ansi
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_reset_units
name|__P
argument_list|(
operator|(
expr|struct
name|hba_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SCSI_FOUNDTARGET
parameter_list|(
name|hba
parameter_list|,
name|targ
parameter_list|)
value|{ \ 	extern int scsi_targprint(void *, char *); \ 	int _t = targ; \ 	config_found(&(hba)->hba_dev, (void *)&_t, scsi_targprint); \ }
end_define

end_unit

