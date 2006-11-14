begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Ed Schouten<ed@fxq.nl>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The descriptor has no output report format, thus preventing you from  * controlling the LEDs and the built-in rumblers.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uByte
name|uhid_xb360gp_report_descr
index|[]
init|=
block|{
literal|0x05
block|,
literal|0x01
block|,
comment|/* USAGE PAGE (Generic Desktop)		*/
literal|0x09
block|,
literal|0x05
block|,
comment|/* USAGE (Gamepad)			*/
literal|0xa1
block|,
literal|0x01
block|,
comment|/* COLLECTION (Application)		*/
comment|/* Unused */
literal|0x75
block|,
literal|0x08
block|,
comment|/*  REPORT SIZE (8)			*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*  REPORT COUNT (1)			*/
literal|0x81
block|,
literal|0x01
block|,
comment|/*  INPUT (Constant)			*/
comment|/* Byte count */
literal|0x75
block|,
literal|0x08
block|,
comment|/*  REPORT SIZE (8)			*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*  REPORT COUNT (1)			*/
literal|0x05
block|,
literal|0x01
block|,
comment|/*  USAGE PAGE (Generic Desktop)	*/
literal|0x09
block|,
literal|0x3b
block|,
comment|/*  USAGE (Byte Count)			*/
literal|0x81
block|,
literal|0x01
block|,
comment|/*  INPUT (Constant)			*/
comment|/* D-Pad */
literal|0x05
block|,
literal|0x01
block|,
comment|/*  USAGE PAGE (Generic Desktop)	*/
literal|0x09
block|,
literal|0x01
block|,
comment|/*  USAGE (Pointer)			*/
literal|0xa1
block|,
literal|0x00
block|,
comment|/*  COLLECTION (Physical)		*/
literal|0x75
block|,
literal|0x01
block|,
comment|/*   REPORT SIZE (1)			*/
literal|0x15
block|,
literal|0x00
block|,
comment|/*   LOGICAL MINIMUM (0)		*/
literal|0x25
block|,
literal|0x01
block|,
comment|/*   LOGICAL MAXIMUM (1)		*/
literal|0x35
block|,
literal|0x00
block|,
comment|/*   PHYSICAL MINIMUM (0)		*/
literal|0x45
block|,
literal|0x01
block|,
comment|/*   PHYSICAL MAXIMUM (1)		*/
literal|0x95
block|,
literal|0x04
block|,
comment|/*   REPORT COUNT (4)			*/
literal|0x05
block|,
literal|0x01
block|,
comment|/*   USAGE PAGE (Generic Desktop)	*/
literal|0x09
block|,
literal|0x90
block|,
comment|/*   USAGE (D-Pad Up)			*/
literal|0x09
block|,
literal|0x91
block|,
comment|/*   USAGE (D-Pad Down)			*/
literal|0x09
block|,
literal|0x93
block|,
comment|/*   USAGE (D-Pad Left)			*/
literal|0x09
block|,
literal|0x92
block|,
comment|/*   USAGE (D-Pad Right)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*   INPUT (Data, Variable, Absolute)	*/
literal|0xc0
block|,
comment|/*  END COLLECTION			*/
comment|/* Buttons 5-11 */
literal|0x75
block|,
literal|0x01
block|,
comment|/*  REPORT SIZE (1)			*/
literal|0x15
block|,
literal|0x00
block|,
comment|/*  LOGICAL MINIMUM (0)			*/
literal|0x25
block|,
literal|0x01
block|,
comment|/*  LOGICAL MAXIMUM (1)			*/
literal|0x35
block|,
literal|0x00
block|,
comment|/*  PHYSICAL MINIMUM (0)		*/
literal|0x45
block|,
literal|0x01
block|,
comment|/*  PHYSICAL MAXIMUM (1)		*/
literal|0x95
block|,
literal|0x07
block|,
comment|/*  REPORT COUNT (7)			*/
literal|0x05
block|,
literal|0x09
block|,
comment|/*  USAGE PAGE (Button)			*/
literal|0x09
block|,
literal|0x08
block|,
comment|/*  USAGE (Button 8)			*/
literal|0x09
block|,
literal|0x07
block|,
comment|/*  USAGE (Button 7)			*/
literal|0x09
block|,
literal|0x09
block|,
comment|/*  USAGE (Button 9)			*/
literal|0x09
block|,
literal|0x0a
block|,
comment|/*  USAGE (Button 10)			*/
literal|0x09
block|,
literal|0x05
block|,
comment|/*  USAGE (Button 5)			*/
literal|0x09
block|,
literal|0x06
block|,
comment|/*  USAGE (Button 6)			*/
literal|0x09
block|,
literal|0x0b
block|,
comment|/*  USAGE (Button 11)			*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*  INPUT (Data, Variable, Absolute)	*/
comment|/* Unused */
literal|0x75
block|,
literal|0x01
block|,
comment|/*  REPORT SIZE (1)			*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*  REPORT COUNT (1)			*/
literal|0x81
block|,
literal|0x01
block|,
comment|/*  INPUT (Constant)			*/
comment|/* Buttons 1-4 */
literal|0x75
block|,
literal|0x01
block|,
comment|/*  REPORT SIZE (1)			*/
literal|0x15
block|,
literal|0x00
block|,
comment|/*  LOGICAL MINIMUM (0)			*/
literal|0x25
block|,
literal|0x01
block|,
comment|/*  LOGICAL MAXIMUM (1)			*/
literal|0x35
block|,
literal|0x00
block|,
comment|/*  PHYSICAL MINIMUM (0)		*/
literal|0x45
block|,
literal|0x01
block|,
comment|/*  PHYSICAL MAXIMUM (1)		*/
literal|0x95
block|,
literal|0x04
block|,
comment|/*  REPORT COUNT (4)			*/
literal|0x05
block|,
literal|0x09
block|,
comment|/*  USAGE PAGE (Button)			*/
literal|0x19
block|,
literal|0x01
block|,
comment|/*  USAGE MINIMUM (Button 1)		*/
literal|0x29
block|,
literal|0x04
block|,
comment|/*  USAGE MAXIMUM (Button 4)		*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*  INPUT (Data, Variable, Absolute)	*/
comment|/* Triggers */
literal|0x75
block|,
literal|0x08
block|,
comment|/*  REPORT SIZE (8)			*/
literal|0x15
block|,
literal|0x00
block|,
comment|/*  LOGICAL MINIMUM (0)			*/
literal|0x26
block|,
literal|0xff
block|,
literal|0x00
block|,
comment|/*  LOGICAL MAXIMUM (255)		*/
literal|0x35
block|,
literal|0x00
block|,
comment|/*  PHYSICAL MINIMUM (0)		*/
literal|0x46
block|,
literal|0xff
block|,
literal|0x00
block|,
comment|/*  PHYSICAL MAXIMUM (255)		*/
literal|0x95
block|,
literal|0x02
block|,
comment|/*  REPORT SIZE (2)			*/
literal|0x05
block|,
literal|0x01
block|,
comment|/*  USAGE PAGE (Generic Desktop)	*/
literal|0x09
block|,
literal|0x32
block|,
comment|/*  USAGE (Z)				*/
literal|0x09
block|,
literal|0x35
block|,
comment|/*  USAGE (Rz)				*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*  INPUT (Data, Variable, Absolute)	*/
comment|/* Sticks */
literal|0x75
block|,
literal|0x10
block|,
comment|/*  REPORT SIZE (16)			*/
literal|0x16
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|/*  LOGICAL MINIMUM (-32768)		*/
literal|0x26
block|,
literal|0xff
block|,
literal|0x7f
block|,
comment|/*  LOGICAL MAXIMUM (32767)		*/
literal|0x36
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|/*  PHYSICAL MINIMUM (-32768)		*/
literal|0x46
block|,
literal|0xff
block|,
literal|0x7f
block|,
comment|/*  PHYSICAL MAXIMUM (32767)		*/
literal|0x95
block|,
literal|0x04
block|,
comment|/*  REPORT COUNT (4)			*/
literal|0x05
block|,
literal|0x01
block|,
comment|/*  USAGE PAGE (Generic Desktop)	*/
literal|0x09
block|,
literal|0x30
block|,
comment|/*  USAGE (X)				*/
literal|0x09
block|,
literal|0x31
block|,
comment|/*  USAGE (Y)				*/
literal|0x09
block|,
literal|0x33
block|,
comment|/*  USAGE (Rx)				*/
literal|0x09
block|,
literal|0x34
block|,
comment|/*  USAGE (Ry)				*/
literal|0x81
block|,
literal|0x02
block|,
comment|/*  INPUT (Data, Variable, Absolute)	*/
comment|/* Unused */
literal|0x75
block|,
literal|0x30
block|,
comment|/*  REPORT SIZE (48)			*/
literal|0x95
block|,
literal|0x01
block|,
comment|/*  REPORT COUNT (1)			*/
literal|0x81
block|,
literal|0x01
block|,
comment|/*  INPUT (Constant)			*/
literal|0xc0
block|,
comment|/* END COLLECTION			*/
block|}
decl_stmt|;
end_decl_stmt

end_unit

