begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for various on board processors on the soundcards. For  * example DSP processors.  */
end_comment

begin_comment
comment|/*  * Coprocessor access types   */
end_comment

begin_define
define|#
directive|define
name|COPR_CUSTOM
value|0x0001
end_define

begin_comment
comment|/* Custom applications */
end_comment

begin_define
define|#
directive|define
name|COPR_MIDI
value|0x0002
end_define

begin_comment
comment|/* MIDI (MPU-401) emulation */
end_comment

begin_define
define|#
directive|define
name|COPR_PCM
value|0x0004
end_define

begin_comment
comment|/* Digitized voice applications */
end_comment

begin_define
define|#
directive|define
name|COPR_SYNTH
value|0x0008
end_define

begin_comment
comment|/* Music synthesis */
end_comment

end_unit

