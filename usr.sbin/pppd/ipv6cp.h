begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*     ipv6cp.h - PPP IPV6 Control Protocol.     Copyright (C) 1999  Tommi Komulainen<Tommi.Komulainen@iki.fi>      Redistribution and use in source and binary forms are permitted     provided that the above copyright notice and this paragraph are     duplicated in all such forms.  The name of the author may not be     used to endorse or promote products derived from this software     without specific prior written permission.     THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR     IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED     WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */
end_comment

begin_comment
comment|/*  Original version, based on RFC2023 :      Copyright (c) 1995, 1996, 1997 Francis.Dupont@inria.fr, INRIA Rocquencourt,     Alain.Durand@imag.fr, IMAG,     Jean-Luc.Richier@imag.fr, IMAG-LSR.      Copyright (c) 1998, 1999 Francis.Dupont@inria.fr, GIE DYADE,     Alain.Durand@imag.fr, IMAG,     Jean-Luc.Richier@imag.fr, IMAG-LSR.      Ce travail a été fait au sein du GIE DYADE (Groupement d'Intérêt     Économique ayant pour membres BULL S.A. et l'INRIA).      Ce logiciel informatique est disponible aux conditions     usuelles dans la recherche, c'est-à-dire qu'il peut     être utilisé, copié, modifié, distribué à l'unique     condition que ce texte soit conservé afin que     l'origine de ce logiciel soit reconnue.      Le nom de l'Institut National de Recherche en Informatique     et en Automatique (INRIA), de l'IMAG, ou d'une personne morale     ou physique ayant participé à l'élaboration de ce logiciel ne peut     être utilisé sans son accord préalable explicite.      Ce logiciel est fourni tel quel sans aucune garantie,     support ou responsabilité d'aucune sorte.     Ce logiciel est dérivé de sources d'origine     "University of California at Berkeley" et     "Digital Equipment Corporation" couvertes par des copyrights.      L'Institut d'Informatique et de Mathématiques Appliquées de Grenoble (IMAG)     est une fédération d'unités mixtes de recherche du CNRS, de l'Institut National     Polytechnique de Grenoble et de l'Université Joseph Fourier regroupant     sept laboratoires dont le laboratoire Logiciels, Systèmes, Réseaux (LSR).      This work has been done in the context of GIE DYADE (joint R& D venture     between BULL S.A. and INRIA).      This software is available with usual "research" terms     with the aim of retain credits of the software.      Permission to use, copy, modify and distribute this software for any     purpose and without fee is hereby granted, provided that the above     copyright notice and this permission notice appear in all copies,     and the name of INRIA, IMAG, or any contributor not be used in advertising     or publicity pertaining to this material without the prior explicit     permission. The software is provided "as is" without any     warranties, support or liabilities of any kind.     This software is derived from source code from     "University of California at Berkeley" and     "Digital Equipment Corporation" protected by copyrights.      Grenoble's Institute of Computer Science and Applied Mathematics (IMAG)     is a federation of seven research units funded by the CNRS, National     Polytechnic Institute of Grenoble and University Joseph Fourier.     The research unit in Software, Systems, Networks (LSR) is member of IMAG. */
end_comment

begin_comment
comment|/*  * Derived from :  *  *  * ipcp.h - IP Control Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: ipv6cp.h,v 1.3 1999/09/30 19:57:45 masputra Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Options.  */
end_comment

begin_define
define|#
directive|define
name|CI_IFACEID
value|1
end_define

begin_comment
comment|/* Interface Identifier */
end_comment

begin_define
define|#
directive|define
name|CI_COMPRESSTYPE
value|2
end_define

begin_comment
comment|/* Compression Type     */
end_comment

begin_comment
comment|/* No compression types yet defined.  *#define IPV6CP_COMP	0x004f  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipv6cp_options
block|{
name|int
name|neg_ifaceid
decl_stmt|;
comment|/* Negotiate interface identifier? */
name|int
name|req_ifaceid
decl_stmt|;
comment|/* Ask peer to send interface identifier? */
name|int
name|accept_local
decl_stmt|;
comment|/* accept peer's value for iface id? */
name|int
name|opt_local
decl_stmt|;
comment|/* ourtoken set by option */
name|int
name|opt_remote
decl_stmt|;
comment|/* histoken set by option */
name|int
name|use_ip
decl_stmt|;
comment|/* use IP as interface identifier */
if|#
directive|if
name|defined
argument_list|(
name|SOL2
argument_list|)
name|int
name|use_persistent
decl_stmt|;
comment|/* use uniquely persistent value for address */
endif|#
directive|endif
comment|/* defined(SOL2) */
name|int
name|neg_vj
decl_stmt|;
comment|/* Van Jacobson Compression? */
name|u_short
name|vj_protocol
decl_stmt|;
comment|/* protocol value to use in VJ option */
name|eui64_t
name|ourid
decl_stmt|,
name|hisid
decl_stmt|;
comment|/* Interface identifiers */
block|}
name|ipv6cp_options
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|fsm
name|ipv6cp_fsm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipv6cp_options
name|ipv6cp_wantoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipv6cp_options
name|ipv6cp_gotoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipv6cp_options
name|ipv6cp_allowoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipv6cp_options
name|ipv6cp_hisoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protent
name|ipv6cp_protent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|setifaceid
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

