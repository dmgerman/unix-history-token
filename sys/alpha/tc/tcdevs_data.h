begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: tcdevs_data.h,v 1.12 1998/06/18 23:29:46 jonathan Exp $	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	NetBSD: tcdevs,v 1.10 1998/06/18 23:28:12 jonathan Exp   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_decl_stmt
name|struct
name|tc_knowndev
name|tc_knowndevs
index|[]
init|=
block|{
block|{
literal|"AV01B-AA"
block|,
name|TC_DEVICE_AV01B_AA
block|,
name|TC_DESCRIPTION_AV01B_AA
block|, 	}
block|,
block|{
literal|"DGLTA-FA"
block|,
name|TC_DEVICE_DGLTA_FA
block|,
name|TC_DESCRIPTION_DGLTA_FA
block|, 	}
block|,
block|{
literal|"FORE_ATM"
block|,
name|TC_DEVICE_FORE_ATM
block|,
name|TC_DESCRIPTION_FORE_ATM
block|, 	}
block|,
block|{
literal|"KZTSA-AA"
block|,
name|TC_DEVICE_KZTSA_AA
block|,
name|TC_DESCRIPTION_KZTSA_AA
block|, 	}
block|,
block|{
literal|"OTTO    "
block|,
name|TC_DEVICE_OTTO
block|,
name|TC_DESCRIPTION_OTTO
block|, 	}
block|,
block|{
literal|"PMAD-AA "
block|,
name|TC_DEVICE_PMAD_AA
block|,
name|TC_DESCRIPTION_PMAD_AA
block|, 	}
block|,
block|{
literal|"PMAF-AA "
block|,
name|TC_DEVICE_PMAF_AA
block|,
name|TC_DESCRIPTION_PMAF_AA
block|, 	}
block|,
block|{
literal|"PMAF-F  "
block|,
name|TC_DEVICE_PMAF_F
block|,
name|TC_DESCRIPTION_PMAF_F
block|, 	}
block|,
block|{
literal|"PMAG-AA "
block|,
name|TC_DEVICE_PMAG_AA
block|,
name|TC_DESCRIPTION_PMAG_AA
block|, 	}
block|,
block|{
literal|"PMAG-BA "
block|,
name|TC_DEVICE_PMAG_BA
block|,
name|TC_DESCRIPTION_PMAG_BA
block|, 	}
block|,
block|{
literal|"PMAG-CA "
block|,
name|TC_DEVICE_PMAG_CA
block|,
name|TC_DESCRIPTION_PMAG_CA
block|, 	}
block|,
block|{
literal|"PMAG-DA "
block|,
name|TC_DEVICE_PMAG_DA
block|,
name|TC_DESCRIPTION_PMAG_DA
block|, 	}
block|,
block|{
literal|"PMAG-DV "
block|,
name|TC_DEVICE_PMAG_DV
block|,
name|TC_DESCRIPTION_PMAG_DV
block|, 	}
block|,
block|{
literal|"PMAG-FA "
block|,
name|TC_DEVICE_PMAG_FA
block|,
name|TC_DESCRIPTION_PMAG_FA
block|, 	}
block|,
block|{
literal|"PMAGB-BA"
block|,
name|TC_DEVICE_PMAGB_BA
block|,
name|TC_DESCRIPTION_PMAGB_BA
block|, 	}
block|,
block|{
literal|"PMAGD   "
block|,
name|TC_DEVICE_PMAGD
block|,
name|TC_DESCRIPTION_PMAGD
block|, 	}
block|,
block|{
literal|"PMAGD-AA"
block|,
name|TC_DEVICE_PMAGD_AA
block|,
name|TC_DESCRIPTION_PMAGD_AA
block|, 	}
block|,
block|{
literal|"PMAGD-BA"
block|,
name|TC_DEVICE_PMAGD_BA
block|,
name|TC_DESCRIPTION_PMAGD_BA
block|, 	}
block|,
block|{
literal|"PMAZ-AA "
block|,
name|TC_DEVICE_PMAZ_AA
block|,
name|TC_DESCRIPTION_PMAZ_AA
block|, 	}
block|,
block|{
literal|"PMAZ-DS "
block|,
name|TC_DEVICE_PMAZ_DS
block|,
name|TC_DESCRIPTION_PMAZ_DS
block|, 	}
block|,
block|{
literal|"PMAZ-FS "
block|,
name|TC_DEVICE_PMAZ_FS
block|,
name|TC_DESCRIPTION_PMAZ_FS
block|, 	}
block|,
block|{
literal|"PMAZB-AA"
block|,
name|TC_DEVICE_PMAZB_AA
block|,
name|TC_DESCRIPTION_PMAZB_AA
block|, 	}
block|,
block|{
literal|"PMAZC-AA"
block|,
name|TC_DEVICE_PMAZC_AA
block|,
name|TC_DESCRIPTION_PMAZC_AA
block|, 	}
block|,
block|{
literal|"T1D4PKT "
block|,
name|TC_DEVICE_T1D4PKT
block|,
name|TC_DESCRIPTION_T1D4PKT
block|, 	}
block|,
block|{
literal|"T3PKT   "
block|,
name|TC_DEVICE_T3PKT
block|,
name|TC_DESCRIPTION_T3PKT
block|, 	}
block|,
block|{
literal|"PMAT-AA "
block|,
name|TC_DEVICE_PMAT_AA
block|,
name|TC_DESCRIPTION_PMAT_AA
block|, 	}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|, }
block|}
decl_stmt|;
end_decl_stmt

end_unit

