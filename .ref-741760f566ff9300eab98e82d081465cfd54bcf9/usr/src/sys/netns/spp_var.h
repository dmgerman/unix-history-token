begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)spp_var.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Sp control block, one per connection  */
end_comment

begin_struct
struct|struct
name|sppcb
block|{
name|struct
name|spidp_q
name|s_q
decl_stmt|;
comment|/* queue for out-of-order receipt */
name|struct
name|nspcb
modifier|*
name|s_nspcb
decl_stmt|;
comment|/* backpointer to internet pcb */
name|u_char
name|s_state
decl_stmt|;
name|u_char
name|s_flags
decl_stmt|;
define|#
directive|define
name|SF_AK
value|0x01
comment|/* Acknowledgement requested */
define|#
directive|define
name|SF_DELACK
value|0x02
comment|/* Ak, waiting to see if we xmit*/
define|#
directive|define
name|SF_HI
value|0x04
comment|/* Show headers on input */
define|#
directive|define
name|SF_HO
value|0x08
comment|/* Show headers on output */
define|#
directive|define
name|SF_PI
value|0x10
comment|/* Packet (datagram) interface */
name|u_short
name|s_mtu
decl_stmt|;
comment|/* Max packet size for this stream */
comment|/* use sequence fields in headers to store sequence numbers for this    connection */
name|struct
name|spidp
name|s_shdr
decl_stmt|;
comment|/* prototype header to transmit */
define|#
directive|define
name|s_cc
value|s_shdr.si_cc
comment|/* connection control (for EM bit) */
define|#
directive|define
name|s_dt
value|s_shdr.si_dt
comment|/* datastream type */
define|#
directive|define
name|s_sid
value|s_shdr.si_sid
comment|/* source connection identifier */
define|#
directive|define
name|s_did
value|s_shdr.si_did
comment|/* destination connection identifier */
define|#
directive|define
name|s_seq
value|s_shdr.si_seq
comment|/* sequence number */
define|#
directive|define
name|s_ack
value|s_shdr.si_ack
comment|/* acknowledge number */
define|#
directive|define
name|s_alo
value|s_shdr.si_alo
comment|/* allocation number */
define|#
directive|define
name|s_dport
value|s_shdr.si_dna.x_port
comment|/* where we are sending */
name|struct
name|sphdr
name|s_rhdr
decl_stmt|;
comment|/* last received header (in effect!)*/
name|u_short
name|s_rack
decl_stmt|;
comment|/* their acknowledge number */
name|u_short
name|s_ralo
decl_stmt|;
comment|/* their allocation number */
name|u_short
name|s_snt
decl_stmt|;
comment|/* highest packet # we have sent */
comment|/* timeout stuff */
name|short
name|s_idle
decl_stmt|;
comment|/* time idle */
name|short
name|s_timer
index|[
name|TCPT_NTIMERS
index|]
decl_stmt|;
comment|/* timers */
name|short
name|s_rxtshift
decl_stmt|;
comment|/* log(2) of rexmt exp. backoff */
name|u_short
name|s_rtseq
decl_stmt|;
comment|/* packet being timed */
name|short
name|s_rtt
decl_stmt|;
comment|/* timer for round trips */
name|short
name|s_srtt
decl_stmt|;
comment|/* averaged timer */
name|char
name|s_force
decl_stmt|;
comment|/* which timer expired */
comment|/* out of band data */
name|char
name|s_oobflags
decl_stmt|;
define|#
directive|define
name|SF_SOOB
value|0x08
comment|/* sending out of band data */
define|#
directive|define
name|SF_IOOB
value|0x10
comment|/* receiving out of band data */
name|char
name|s_iobc
decl_stmt|;
comment|/* input characters */
comment|/* debug stuff */
name|u_short
name|s_want
decl_stmt|;
comment|/* Last candidate for sending */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nstosppcb
parameter_list|(
name|np
parameter_list|)
value|((struct sppcb *)(np)->nsp_pcb)
end_define

begin_define
define|#
directive|define
name|sotosppcb
parameter_list|(
name|so
parameter_list|)
value|(nstosppcb(sotonspcb(so)))
end_define

begin_struct
struct|struct
name|spp_istat
block|{
name|short
name|hdrops
decl_stmt|;
name|short
name|badsum
decl_stmt|;
name|short
name|badlen
decl_stmt|;
name|short
name|slotim
decl_stmt|;
name|short
name|fastim
decl_stmt|;
name|short
name|nonucn
decl_stmt|;
name|short
name|noconn
decl_stmt|;
name|short
name|notme
decl_stmt|;
name|short
name|wrncon
decl_stmt|;
name|short
name|bdreas
decl_stmt|;
name|short
name|gonawy
decl_stmt|;
name|short
name|notyet
decl_stmt|;
name|short
name|lstdup
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|spp_istat
name|spp_istat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|spp_iss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sppcb
modifier|*
name|spp_close
argument_list|()
decl_stmt|,
modifier|*
name|spp_disconnect
argument_list|()
decl_stmt|,
modifier|*
name|spp_usrclosed
argument_list|()
decl_stmt|,
modifier|*
name|spp_timers
argument_list|()
decl_stmt|,
modifier|*
name|spp_drop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPP_ISSINCR
value|128
end_define

begin_comment
comment|/*  * SPP sequence numbers are 16 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare such integers.  */
end_comment

begin_define
define|#
directive|define
name|SSEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))< 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))<= 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))> 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))>= 0)
end_define

end_unit

