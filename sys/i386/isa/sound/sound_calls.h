begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	DMA buffer calls  */
end_comment

begin_function_decl
name|int
name|DMAbuf_open
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_release
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_getwrbuffer
parameter_list|(
name|int
name|dev
parameter_list|,
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|size
parameter_list|,
name|int
name|dontblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_getrdbuffer
parameter_list|(
name|int
name|dev
parameter_list|,
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|int
name|dontblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_rmchars
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|buff_no
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_start_output
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|buff_no
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_ioctl
parameter_list|(
name|int
name|dev
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|,
name|int
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DMAbuf_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_start_dma
parameter_list|(
name|int
name|dev
parameter_list|,
name|u_long
name|physaddr
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|dma_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DMAbuf_open_dma
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DMAbuf_close_dma
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DMAbuf_reset_dma
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DMAbuf_inputintr
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DMAbuf_outputintr
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|underflow_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DMAbuf_start_devices
parameter_list|(
name|u_int
name|devmask
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_SELECT
end_ifdef

begin_function_decl
name|int
name|DMAbuf_select
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|int
name|sel_type
parameter_list|,
name|select_table
modifier|*
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	System calls for /dev/dsp and /dev/audio  */
end_comment

begin_function_decl
name|int
name|audio_read
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audio_write
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audio_open
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audio_release
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audio_ioctl
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audio_lseek
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* long audio_init (void); */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_SELECT
end_ifdef

begin_function_decl
name|int
name|audio_poll
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|int
name|events
parameter_list|,
name|select_table
modifier|*
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	System calls for the /dev/sequencer  */
end_comment

begin_function_decl
name|int
name|sequencer_read
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sequencer_write
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sequencer_open
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sequencer_release
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sequencer_ioctl
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sequencer_lseek
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sequencer_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sequencer_timer
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|note_to_freq
parameter_list|(
name|int
name|note_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|compute_finetune
parameter_list|(
name|u_long
name|base_freq
parameter_list|,
name|int
name|bend
parameter_list|,
name|int
name|range
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seq_input_event
parameter_list|(
name|u_char
modifier|*
name|event
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seq_copy_to_input
parameter_list|(
name|u_char
modifier|*
name|event
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	System calls for the /dev/midi  */
end_comment

begin_function_decl
name|int
name|MIDIbuf_read
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MIDIbuf_write
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MIDIbuf_open
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MIDIbuf_release
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MIDIbuf_ioctl
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MIDIbuf_lseek
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MIDIbuf_bytes_received
parameter_list|(
name|int
name|dev
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  *	Misc calls from various sources  */
end_comment

begin_comment
comment|/*	From soundcard.c	*/
end_comment

begin_function_decl
name|void
name|soundcard_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tenmicrosec
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|request_sound_timer
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sound_stop_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_ioctl_return
parameter_list|(
name|int
modifier|*
name|addr
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_set_irq_handler
parameter_list|(
name|int
name|int_lvl
parameter_list|,
name|void
function_decl|(
modifier|*
name|hndlr
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
name|sound_os_info
modifier|*
name|osp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sound_dma_malloc
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sound_dma_free
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conf_printf
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conf_printf2
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|,
name|int
name|dma2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sound_switch.c	*/
end_comment

begin_function_decl
name|int
name|sound_read_sw
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sound_write_sw
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sound_open_sw
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sound_release_sw
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sound_ioctl_sw
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sb_dsp.c	*/
end_comment

begin_function_decl
name|int
name|sb_dsp_detect
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_dsp_init
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_dsp_disable_midi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_dsp_command
parameter_list|(
name|u_char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_reset_dsp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sb16_dsp.c	*/
end_comment

begin_function_decl
name|void
name|sb16_dsp_interrupt
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb16_dsp_init
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb16_dsp_detect
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sb16_midi.c	*/
end_comment

begin_function_decl
name|void
name|sb16midiintr
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_sb16midi
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_sb16midi
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_midi_interrupt
parameter_list|(
name|int
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sb_midi.c	*/
end_comment

begin_function_decl
name|void
name|sb_midi_init
parameter_list|(
name|int
name|model
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sb_mixer.c	*/
end_comment

begin_function_decl
name|void
name|sb_setmixer
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_getmixer
parameter_list|(
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_mixer_set_stereo
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_mixer_init
parameter_list|(
name|int
name|major_model
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From opl3.c	*/
end_comment

begin_function_decl
name|int
name|opl3_detect
parameter_list|(
name|int
name|ioaddr
parameter_list|,
name|sound_os_info
modifier|*
name|osp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|opl3_init
parameter_list|(
name|int
name|ioaddr
parameter_list|,
name|sound_os_info
modifier|*
name|osp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sb_card.c	*/
end_comment

begin_function_decl
name|void
name|attach_sb_card
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_sb
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  From awe_wave.c  */
end_comment

begin_function_decl
name|void
name|attach_awe_obsolete
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_awe_obsolete
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From adlib_card.c	*/
end_comment

begin_function_decl
name|void
name|attach_adlib_card
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_adlib
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From pas_card.c	*/
end_comment

begin_function_decl
name|void
name|attach_pas_card
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_pas
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pas_set_intr
parameter_list|(
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pas_remove_intr
parameter_list|(
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
name|pas_read
parameter_list|(
name|int
name|ioaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pas_write
parameter_list|(
name|u_char
name|data
parameter_list|,
name|int
name|ioaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From pas_audio.c */
end_comment

begin_function_decl
name|void
name|pas_pcm_interrupt
parameter_list|(
name|u_char
name|status
parameter_list|,
name|int
name|cause
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pas_pcm_init
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From pas_mixer.c */
end_comment

begin_function_decl
name|int
name|pas_init_mixer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From pas_midi.c */
end_comment

begin_function_decl
name|void
name|pas_midi_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pas_midi_interrupt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From gus_card.c */
end_comment

begin_function_decl
name|void
name|attach_gus_card
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_gus
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gus_set_midi_irq
parameter_list|(
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*void gusintr(int irq); */
end_comment

begin_function_decl
name|void
name|attach_gus_db16
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_gus_db16
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From gus_wave.c */
end_comment

begin_function_decl
name|int
name|gus_wave_detect
parameter_list|(
name|int
name|baseaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gus_wave_init
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gus_voice_irq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
name|gus_read8
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gus_write8
parameter_list|(
name|int
name|reg
parameter_list|,
name|u_int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|guswave_dma_irq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gus_delay
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gus_default_mixer_ioctl
parameter_list|(
name|int
name|dev
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gus_timer_command
parameter_list|(
name|u_int
name|addr
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From gus_midi.c */
end_comment

begin_function_decl
name|void
name|gus_midi_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gus_midi_interrupt
parameter_list|(
name|int
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From mpu401.c */
end_comment

begin_function_decl
name|void
name|attach_mpu401
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_mpu401
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpuintr
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From uart6850.c */
end_comment

begin_function_decl
name|void
name|attach_uart6850
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_uart6850
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From opl3.c */
end_comment

begin_function_decl
name|void
name|enable_opl3_mode
parameter_list|(
name|int
name|left
parameter_list|,
name|int
name|right
parameter_list|,
name|int
name|both
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From patmgr.c */
end_comment

begin_function_decl
name|int
name|pmgr_open
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmgr_release
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmgr_read
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmgr_write
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmgr_access
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|patmgr_info
modifier|*
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmgr_inform
parameter_list|(
name|int
name|dev
parameter_list|,
name|int
name|event
parameter_list|,
name|u_long
name|parm1
parameter_list|,
name|u_long
name|parm2
parameter_list|,
name|u_long
name|parm3
parameter_list|,
name|u_long
name|parm4
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 	From ics2101.c */
end_comment

begin_function_decl
name|void
name|ics2101_mixer_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sound_timer.c */
end_comment

begin_function_decl
name|void
name|sound_timer_interrupt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sound_timer_syncinterval
parameter_list|(
name|u_int
name|new_usecs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From ad1848.c */
end_comment

begin_function_decl
name|void
name|ad1848_init
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|io_base
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma_playback
parameter_list|,
name|int
name|dma_capture
parameter_list|,
name|int
name|share_dma
parameter_list|,
name|sound_os_info
modifier|*
name|osp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ad1848_detect
parameter_list|(
name|int
name|io_base
parameter_list|,
name|int
modifier|*
name|flags
parameter_list|,
name|sound_os_info
modifier|*
name|osp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AD_F_CS4231
value|0x0001
end_define

begin_comment
comment|/* Returned if a CS4232 (or compatible) detected */
end_comment

begin_define
define|#
directive|define
name|AD_F_CS4248
value|0x0001
end_define

begin_comment
comment|/* Returned if a CS4248 (or compatible) detected */
end_comment

begin_function_decl
name|void
name|ad1848_interrupt
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_mss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_mss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_pnp_ad1848
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_pnp_ad1848
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 	From pss.c */
end_comment

begin_function_decl
name|int
name|probe_pss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_pss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_pss_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_pss_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_pss_mss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_pss_mss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 	From sscape.c */
end_comment

begin_function_decl
name|int
name|probe_sscape
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_sscape
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_ss_mss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_ss_mss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pss_read
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pss_write
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|snd_rw_buf
modifier|*
name|buf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pss_open
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pss_release
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pss_ioctl
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|ioctl_arg
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pss_lseek
parameter_list|(
name|int
name|dev
parameter_list|,
name|struct
name|fileinfo
modifier|*
name|file
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pss_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From aedsp16.c */
end_comment

begin_function_decl
name|int
name|InitAEDSP16_SBPRO
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|InitAEDSP16_MSS
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|InitAEDSP16_MPU401
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From midi_synth.c	*/
end_comment

begin_function_decl
name|void
name|do_midi_msg
parameter_list|(
name|int
name|synthno
parameter_list|,
name|u_char
modifier|*
name|msg
parameter_list|,
name|int
name|mlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From trix.c	*/
end_comment

begin_function_decl
name|void
name|attach_trix_wss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_trix_wss
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_trix_sb
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_trix_sb
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_trix_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_trix_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From mad16.c	*/
end_comment

begin_function_decl
name|void
name|attach_mad16
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_mad16
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_mad16_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_mad16_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mad16_sb_dsp_detect
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mad16_sb_dsp_init
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From cs4232.c */
end_comment

begin_function_decl
name|int
name|probe_cs4232
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_cs4232
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_cs4232_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attach_cs4232_mpu
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From maui.c */
end_comment

begin_function_decl
name|void
name|attach_maui
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|probe_maui
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	From sound_pnp.c */
end_comment

begin_function_decl
name|void
name|sound_pnp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sound_pnp_disconnect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

