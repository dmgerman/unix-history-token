begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)autoconf.h	7.3 (Berkeley) %G%  *  * from: $Header: autoconf.h,v 1.10 92/11/26 02:04:32 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Autoconfiguration information.  */
end_comment

begin_comment
comment|/*  * Most devices are configured according to information kept in  * the FORTH PROMs.  In particular, we extract the `name', `reg',  * and `address' properties of each device attached to the mainbus;  * other drives may also use this information.  The mainbus itself  * (which `is' the CPU, in some sense) gets just the node, with a  * fake name ("mainbus").  */
end_comment

begin_define
define|#
directive|define
name|RA_MAXINTR
value|8
end_define

begin_comment
comment|/* max interrupts per device */
end_comment

begin_struct
struct|struct
name|romaux
block|{
specifier|const
name|char
modifier|*
name|ra_name
decl_stmt|;
comment|/* name from FORTH PROM */
name|int
name|ra_node
decl_stmt|;
comment|/* FORTH PROM node ID */
name|int
name|ra_iospace
decl_stmt|;
comment|/* register space (obio, etc) */
name|void
modifier|*
name|ra_paddr
decl_stmt|;
comment|/* register physical address */
name|int
name|ra_len
decl_stmt|;
comment|/* register length */
name|void
modifier|*
name|ra_vaddr
decl_stmt|;
comment|/* ROM mapped virtual address, or 0 */
struct|struct
name|rom_intr
block|{
comment|/* interrupt information: */
name|int
name|int_pri
decl_stmt|;
comment|/* priority (IPL) */
name|int
name|int_vec
decl_stmt|;
comment|/* vector (always 0?) */
block|}
name|ra_intr
index|[
name|RA_MAXINTR
index|]
struct|;
name|int
name|ra_nintr
decl_stmt|;
comment|/* number of interrupt info elements */
name|struct
name|bootpath
modifier|*
name|ra_bp
decl_stmt|;
comment|/* used for locating boot device */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The various getprop* functions obtain `properties' from the ROMs.  * getprop() obtains a property as a byte-sequence, and returns its  * length; the others convert or make some other guarantee.  */
end_comment

begin_decl_stmt
name|int
name|getprop
name|__P
argument_list|(
operator|(
name|int
name|node
operator|,
name|char
operator|*
name|name
operator|,
name|void
operator|*
name|buf
operator|,
name|int
name|bufsiz
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getpropstring
name|__P
argument_list|(
operator|(
name|int
name|node
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getpropint
name|__P
argument_list|(
operator|(
name|int
name|node
operator|,
name|char
operator|*
name|name
operator|,
name|int
name|deflt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frequently used options node */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optionsnode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The romprop function gets physical and virtual addresses from the PROM  * and fills in a romaux.  It returns 1 on success, 0 if the physical  * address is not available as a "reg" property.  */
end_comment

begin_decl_stmt
name|int
name|romprop
name|__P
argument_list|(
operator|(
expr|struct
name|romaux
operator|*
name|ra
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|int
name|node
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The matchbyname function is useful in drivers that are matched  * by romaux name, i.e., all `mainbus attached' devices.  It expects  * its aux pointer to point to a pointer to the name (the address of  * a romaux structure suffices, for instance).  */
end_comment

begin_decl_stmt
name|int
name|matchbyname
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|cfdata
operator|*
name|cf
operator|,
name|void
operator|*
name|aux
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * `clockfreq' produces a printable representation of a clock frequency  * (this is just a frill).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|clockfreq
name|__P
argument_list|(
operator|(
name|int
name|freq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * mapiodev maps an I/O device to a virtual address, returning the address.  * mapdev does the real work: you can supply a special virtual address and  * it will use that instead of creating one, but you must only do this if  * you get it from ../sparc/vaddrs.h.  */
end_comment

begin_decl_stmt
name|void
modifier|*
name|mapdev
name|__P
argument_list|(
operator|(
name|void
operator|*
name|pa
operator|,
name|int
name|va
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mapiodev
parameter_list|(
name|pa
parameter_list|,
name|size
parameter_list|)
value|mapdev(pa, 0, size)
end_define

begin_comment
comment|/*  * Memory description arrays.  Shared between pmap.c and autoconf.c; no  * one else should use this (except maybe mem.c, e.g., if we fix the VM to  * handle discontiguous physical memory).  */
end_comment

begin_struct
struct|struct
name|memarr
block|{
name|u_int
name|addr
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|makememarr
parameter_list|(
name|struct
name|memarr
modifier|*
parameter_list|,
name|int
name|max
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MEMARR_AVAILPHYS
value|0
end_define

begin_define
define|#
directive|define
name|MEMARR_TOTALPHYS
value|1
end_define

begin_comment
comment|/* Pass a string to the FORTH interpreter.  May fail silently. */
end_comment

begin_decl_stmt
name|void
name|rominterpret
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Openprom V2 style boot path */
end_comment

begin_struct
struct|struct
name|bootpath
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name of this node */
name|int
name|val
index|[
literal|2
index|]
decl_stmt|;
comment|/* up to two optional values */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|device
modifier|*
name|bootdv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* found during autoconfiguration */
end_comment

end_unit

