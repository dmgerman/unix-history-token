begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb/ugraphire_rdesc.h,v 1.1 2000/12/29 01:47:49 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Nick Hibma<n_hibma@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_decl_stmt
specifier|static
name|uByte
name|uhid_graphire_report_descr
index|[]
init|=
block|{
literal|0x05
block|,
literal|0x0d
block|,
comment|/*  USAGE_PAGE (Digitizers)		*/
literal|0x09
block|,
literal|0x01
block|,
comment|/*  USAGE (Digitizer)		*/
literal|0xa1
block|,
literal|0x01
block|,
comment|/*  COLLECTION (Application)		*/
literal|0x85
block|,
literal|0x02
block|,
comment|/*    REPORT_ID (2)			*/
literal|0x05
block|,
literal|0x0d
block|,
comment|/*    USAGE_PAGE (Digitizers)	*/
literal|0x09
block|,
literal|0x01
block|,
comment|/*    USAGE (Digitizer)		*/
literal|0xa1
block|,
literal|0x00
block|,
comment|/*    COLLECTION (Physical)		*/
literal|0x15
block|,
literal|0x00
block|,
comment|/*      LOGICAL_MINIMUM (0)		*/
literal|0x25
block|,
literal|0x01
block|,
comment|/*      LOGICAL_MAXIMUM (1)		*/
literal|0x09
block|,
literal|0x33
block|,
comment|/*      USAGE (Touch)		*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*      REPORT_SIZE (1)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x09
block|,
literal|0x44
block|,
comment|/*      USAGE (Barrel Switch)	*/
literal|0x95
block|,
literal|0x02
block|,
comment|/*      REPORT_COUNT (2)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*      REPORT_SIZE (1)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x09
block|,
literal|0x00
block|,
comment|/*      USAGE (Undefined)		*/
literal|0x95
block|,
literal|0x02
block|,
comment|/*      REPORT_COUNT (2)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*      REPORT_SIZE (1)		*/
literal|0x81
block|,
literal|0x03
block|,
comment|/*      INPUT (Cnst,Var,Abs)		*/
literal|0x09
block|,
literal|0x3c
block|,
comment|/*      USAGE (Invert)		*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*      REPORT_SIZE (1)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x09
block|,
literal|0x38
block|,
comment|/*      USAGE (Transducer Index)	*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*      REPORT_SIZE (1)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x09
block|,
literal|0x32
block|,
comment|/*      USAGE (In Range)		*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*      REPORT_SIZE (1)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x05
block|,
literal|0x01
block|,
comment|/*      USAGE_PAGE (Generic Desktop)	*/
literal|0x09
block|,
literal|0x30
block|,
comment|/*      USAGE (X)			*/
literal|0x15
block|,
literal|0x00
block|,
comment|/*      LOGICAL_MINIMUM (0)		*/
literal|0x26
block|,
literal|0xde
block|,
literal|0x27
block|,
comment|/*      LOGICAL_MAXIMUM (10206)	*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x10
block|,
comment|/*      REPORT_SIZE (16)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x09
block|,
literal|0x31
block|,
comment|/*      USAGE (Y)			*/
literal|0x26
block|,
literal|0xfe
block|,
literal|0x1c
block|,
comment|/*      LOGICAL_MAXIMUM (7422)	*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x10
block|,
comment|/*      REPORT_SIZE (16)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0x05
block|,
literal|0x0d
block|,
comment|/*      USAGE_PAGE (Digitizers)	*/
literal|0x09
block|,
literal|0x30
block|,
comment|/*      USAGE (Tip Pressure)		*/
literal|0x26
block|,
literal|0xff
block|,
literal|0x01
block|,
comment|/*      LOGICAL_MAXIMUM (511)	*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*      REPORT_COUNT (1)		*/
literal|0x75
block|,
literal|0x10
block|,
comment|/*      REPORT_SIZE (16)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*      INPUT (Data,Var,Abs)		*/
literal|0xc0
block|,
comment|/*    END_COLLECTION			*/
literal|0x05
block|,
literal|0x0d
block|,
comment|/*    USAGE_PAGE (Digitizers)	*/
literal|0x09
block|,
literal|0x00
block|,
comment|/*    USAGE (Undefined)		*/
literal|0x85
block|,
literal|0x02
block|,
comment|/*    REPORT_ID (2)			*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*    REPORT_COUNT (1)		*/
literal|0xb1
block|,
literal|0x02
block|,
comment|/*    FEATURE (Data,Var,Abs)		*/
literal|0x09
block|,
literal|0x00
block|,
comment|/*    USAGE (Undefined)		*/
literal|0x85
block|,
literal|0x03
block|,
comment|/*    REPORT_ID (3)			*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*    REPORT_COUNT (1)		*/
literal|0xb1
block|,
literal|0x02
block|,
comment|/*    FEATURE (Data,Var,Abs)		*/
literal|0xc0
block|,
comment|/*  END_COLLECTION			*/
block|}
decl_stmt|;
end_decl_stmt

end_unit

