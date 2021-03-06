#include "ui_menu.h"
#include "ui_menu_internal.h"

/*
 * How to create a new menu entry in an existing menu:
 * - Copy an existing entry of MENU_KIND and paste at the desired position
 * - Just assign a unique number to the "number" attribute
 * - Change the label, and implement handling
 *
 * How to create a menu group:
 * - Add menu group id entry to enum below
 * - Create a MenuDescriptor Array with the desired entries, make sure to have the MENU_STOP element at last position
 *   and that all elements have the enum value as first attribute (menuId)
 * - Added the menu group entry in the parent menu descriptor array.
 * - Create a MenuState element
 * - Added the menu group descriptor to the groups list at the position corresponding to the enum value
 *   using the descriptor array, the address of the MenuState and the address of the parent menu descriptor array.
 *
 *
 */

// ATTENTION: The numbering here has to be match in the groups
// data structure found more or less at the end of this
// menu definition block ! Otherwise menu display will not work
// as expected and may crash mcHF
// If you move menus around, make sure to change the groups structure of the move
// menu to reflect the new parent menu!

enum MENU_GROUP_ITEM
{
    MENU_TOP  = 0,
    MENU_BASE,
    MENU_CONF,
    MENU_POW,
    MENU_FILTER,
    MENU_SYSINFO,
    MENU_CW,
    MENU_DISPLAY,
    MENU_DEBUG,
};


const MenuDescriptor topGroup[] =
{
    { MENU_TOP, MENU_GROUP, MENU_BASE, "STD","Standard Menu", UiMenuDesc("Operational parameters") },
    { MENU_TOP, MENU_GROUP, MENU_CONF, "CON","Configuration Menu", UiMenuDesc("Configuration settings typically not so often to be changed") },
    { MENU_TOP, MENU_GROUP, MENU_DISPLAY, "DIS","Display Menu", UiMenuDesc("Everything related to how the display presents data such as colors or speed of display") },
    { MENU_TOP, MENU_GROUP, MENU_CW,"CW ","CW Mode Settings", UiMenuDesc("Everything related to CW Mode operation (except CW PA Bias)") },
    { MENU_TOP, MENU_GROUP, MENU_FILTER, "FIL","Filter Selection", UiMenuDesc("Select the filters for filter button by mode. Each mode can have up to 4 filters for quick selection via short press Filter button G4.") },
    { MENU_TOP, MENU_GROUP, MENU_POW, "POW","PA Configuration", UiMenuDesc("Menu for power amplifier parameter and tune function adjustments") },
    { MENU_TOP, MENU_GROUP, MENU_SYSINFO,"INF","System Info", UiMenuDesc("Lists various system info values") },
    { MENU_TOP, MENU_GROUP, MENU_DEBUG,"INF","Debug/Exper. Settings", UiMenuDesc("As the name says, contains debug or expert settings usually not relevant for operating the mcHF") },
    { MENU_TOP, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor baseGroup[] =
{
//    { MENU_BASE, MENU_ITEM, MENU_SSB_NARROW_FILT,"029","CW Filt in SSB Mode", UiMenuDesc(":soon:") },
    { MENU_BASE, MENU_ITEM, MENU_SSB_AUTO_MODE_SELECT,"031","LSB/USB Auto Select", UiMenuDesc("If enabled, the appropriate sideband mode for SSB and FreeDV is chosen as default for bands by its frequency.")},
    { MENU_BASE, MENU_ITEM, MENU_DIGI_DISABLE,"030","Digital Modes", UiMenuDesc("Disable appearance of digital modes when pressing Mode button")},
    { MENU_BASE, MENU_ITEM, MENU_CW_DISABLE,"030","CW Mode", UiMenuDesc("Disable appearance of CW mode when pressing Mode button")},
    { MENU_BASE, MENU_ITEM, MENU_AM_DISABLE,"030","AM Mode", UiMenuDesc("Disable appearance of AM mode when pressing Mode button")},
    { MENU_BASE, MENU_ITEM, MENU_DEMOD_SAM,"SAM","SyncAM Mode",UiMenuDesc("Disable appearance of SyncAM modeswhen pressing Mode button")  },
    { MENU_BASE, MENU_ITEM, MENU_FM_MODE_ENABLE,"040","FM Mode", UiMenuDesc("Disable appearance of FM mode when pressing Mode button")},
    { MENU_BASE, MENU_ITEM, MENU_FM_GEN_SUBAUDIBLE_TONE,"041","FM Sub Tone Gen", UiMenuDesc("Enable generation of CTCSS tones during FM transmissions.") },
    { MENU_BASE, MENU_ITEM, MENU_FM_DET_SUBAUDIBLE_TONE,"042","FM Sub Tone Det", UiMenuDesc("Enable detection of CTCSS tones during FM receive. RX is muted unless tone is detected.") },
    { MENU_BASE, MENU_ITEM, MENU_FM_TONE_BURST_MODE,"043","FM Tone Burst", UiMenuDesc("Enabled sending of short tone at begin of each FM transmission. Used to open repeaters. Available frequencies are 1750 Hz and 2135 Hz.") },
    { MENU_BASE, MENU_ITEM, MENU_FM_DEV_MODE,"045","FM Deviation", UiMenuDesc("Select between normal and narrow deviation (5 and 2.5kHz) for FM RX/TX") },
    { MENU_BASE, MENU_ITEM, MENU_RF_GAIN_ADJ,"051","RF Gain", UiMenuDesc("RF Receive Gain. This setting is also accessible via Encoder 2, RFG.") }, // also via knob
    { MENU_BASE, MENU_ITEM, MENU_AGC_MODE,"050","AGC Mode", UiMenuDesc("Automatic Gain Control Mode setting. You may select preconfigured settings (SLOW,MED,FAST), define settings yourself (CUSTOM) or use MANUAL (no AGC\, use RFG to control gain") },
    { MENU_BASE, MENU_ITEM, MENU_CUSTOM_AGC,"052","Custom AGC (+=Slower)", UiMenuDesc("If AGC is set to CUSTOM\, this controls the speed setting of AGC") },
    { MENU_BASE, MENU_ITEM, MENU_CODEC_GAIN_MODE,"053","RX Codec Gain", UiMenuDesc("Sets the Codec IQ signal gain. Higher values represent higher gain. If set to AUTO the mcHF controls the gain so that the dynamic range is used best.") },

    { MENU_BASE, MENU_ITEM, MENU_RX_FREQ_CONV,"055","RX/TX Freq Xlate", UiMenuDesc("Controls offset of the receiver IQ signal base frequency from the dial frequency. Use of +/-12Khz is recommended. Switching it to OFF is not recommended as it disables certain features.") },
    { MENU_BASE, MENU_ITEM, MENU_MIC_LINE_MODE,"060","Mic/Line Select", UiMenuDesc("Select used signal input for transmit (except in CW). Also changeable via long press on M3") },
    { MENU_BASE, MENU_ITEM, MENU_MIC_GAIN,"061","Mic Input Gain", UiMenuDesc("Microphone gain. Also changeable via Encoder 3 if Microphone is selected as Input") },
    { MENU_BASE, MENU_ITEM, MENU_LINE_GAIN,"062","Line Input Gain", UiMenuDesc("LineIn gain. Also changeable via Encoder 3 if LineIn Left (L>L) or LineIn Right (L>R) is selected as Input") },

    { MENU_BASE, MENU_ITEM, MENU_TX_COMPRESSION_LEVEL,"065","TX Audio Compress", UiMenuDesc("Control the TX audio compressor. Higher values == more compression. Set to CUSTOM to set user defined compression parameters. See below. Also changeable via Encoder 1 (CMP).") },
    { MENU_BASE, MENU_ITEM, MENU_ALC_RELEASE,"063","TX ALC Release Time", UiMenuDesc("If Audio Compressor Config is set to CUSTOM\, sets the value of the Audio Compressor Release time. Otherwise shows predefined value of selected compression level.") },
    { MENU_BASE, MENU_ITEM, MENU_ALC_POSTFILT_GAIN,"064","TX ALC Input Gain", UiMenuDesc("If Audio Compressor Config is set to CUSTOM\, sets the value of the ALC Input Gain. Otherwise shows predefined value of selected compression level.") },

    { MENU_BASE, MENU_ITEM, MENU_NOISE_BLANKER_SETTING,"054","RX NB Setting", UiMenuDesc("Set the Noise Blanker strength. Higher values mean more agressive blanking. Also changeable using Encoder 2 if Noise Blanker is active.") },

    { MENU_BASE, MENU_ITEM, MENU_DSP_NR_STRENGTH, "010","DSP NR Strength", UiMenuDesc("Set the Noise Reduction Strength. Higher values mean more agressive noise reduction but also higher CPU load. Use with extreme care. Also changeable using Encoder 2 if DSP is active.") }, // via knob

    { MENU_BASE, MENU_ITEM, MENU_TCXO_MODE,"090","TCXO Off/On/Stop", UiMenuDesc("The software TCXO can be turned ON (set frequency is adjusted so that generated frequency matches the wanted frequency); OFF (no correction or measurement done); or STOP (no correction but measurement).") },
    { MENU_BASE, MENU_ITEM, MENU_TCXO_C_F,"091","TCXO Temp. (C/F)", UiMenuDesc("Show the measure TCXO temperature in Celsius or Fahrenheit.") },
    { MENU_BASE, MENU_ITEM, MENU_BACKUP_CONFIG,"197","Backup Config", UiMenuDesc("Backup your I2C Configuration to flash. If you don't have suitable I2C EEPROM installed this function is not available.") },
    { MENU_BASE, MENU_ITEM, MENU_RESTORE_CONFIG,"198","Restore Config", UiMenuDesc("Restore your I2C Configuration from flash. If you don't have suitable I2C EEPROM installed this function is not available.") },
    { MENU_BASE, MENU_ITEM, MENU_RESTART_CODEC,"198","Restart Codec", UiMenuDesc("Sometimes there is a problem with the I2S IQ signal stream from the Codec\, resulting in mirrored signal reception. Restarting the CODEC Stream will cure that problem. Try more than once\, if first call did not help.") },
    { MENU_BASE, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor displayGroup[] =
{
    { MENU_DISPLAY, MENU_ITEM, CONFIG_LCD_AUTO_OFF_MODE,"090","LCD Auto Blank", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, CONFIG_FREQ_STEP_MARKER_LINE,"091","Step Size Marker", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, CONFIG_DISP_FILTER_BANDWIDTH,"092","Filter BW Display", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SPECTRUM_MODE,"109","Spectrum Type", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SPECTRUM_MAGNIFY,"105","Spectrum Magnify", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SPECTRUM_SIZE,"117","Spectrum Size", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SPECTRUM_FILTER_STRENGTH,"101","Spectrum Filter", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SPECTRUM_FREQSCALE_COLOUR,"104","Spec FreqScaleClr", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SPECTRUM_CENTER_LINE_COLOUR,"108","Spectrum LineClr", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, CONFIG_SPECTRUM_FFT_WINDOW_TYPE,"340","Spectrum FFT", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_LIGHT_ENABLE,"99","Scope Light", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_SPEED,"100","Scope 1/Speed", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_AGC_ADJUST,"106","Scope AGC Adj.", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_TRACE_COLOUR,"102","Scope Trace Colour", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_GRID_COLOUR,"103","Scope Grid Colour", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_DB_DIVISION,"107","Scope Div.", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_SCOPE_NOSIG_ADJUST,"115","Scope NoSig Adj.", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_WFALL_SPEED,"114","Wfall 1/Speed", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_WFALL_COLOR_SCHEME,"110","Wfall Colours", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_WFALL_STEP_SIZE,"111","Wfall Step Size", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_WFALL_OFFSET,"112","Wfall Brightness", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_WFALL_CONTRAST,"113","Wfall Contrast", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_WFALL_NOSIG_ADJUST,"116","Wfall NoSig Adj.", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_S_METER,"121","S-Meter", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_METER_COLOUR_UP,"122","Meter Colour Up", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_METER_COLOUR_DOWN,"123","Meter Colour Down", UiMenuDesc(":soon:") },
    { MENU_DISPLAY, MENU_ITEM, MENU_DBM_DISPLAY,"120","dBm display", UiMenuDesc("Enable an additional numeric display of the RX signal strength")},
    { MENU_DISPLAY, MENU_ITEM, MENU_S_METER,"121","S-Meter", UiMenuDesc("Select the S-Meter measurement style. In old school mode, the RF Gain influence the S-Meter settings, higher RFG values increase S-Meter value.")},
    { MENU_DISPLAY, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor cwGroup[] =
{
//    { MENU_CW, MENU_ITEM, MENU_CW_WIDE_FILT,"028","Wide Filt in CW Mode", UiMenuDesc(":soon:") },
    { MENU_CW, MENU_ITEM, MENU_KEYER_MODE,"070","CW Keyer Mode", UiMenuDesc("Select how the mcHF interprets the connected keyer signals. Supported modes: Iambic A and B Keyer (IAM A/B)\, Straight Key (STR_K)\, and Ultimatic Keyer (ULTIM)") },
    { MENU_CW, MENU_ITEM, MENU_KEYER_SPEED,"071","CW Keyer Speed", UiMenuDesc("Keyer Speed for the automatic keyer modes in WpM. Also changeable via Encoder 3 if in CW Mode.") },
    { MENU_CW, MENU_ITEM, MENU_SIDETONE_GAIN,"072","CW Sidetone Gain", UiMenuDesc("Audio volume for the monitor sidetone in CW TX. Also changeable via Encoder 1 if in CW Mode.") },
    { MENU_CW, MENU_ITEM, MENU_SIDETONE_FREQUENCY,"073","CW Side/Offset Freq", UiMenuDesc("Sidetone Frequency (also Offset frequency\, see CW Freq. Offset below)") },
    { MENU_CW, MENU_ITEM, MENU_PADDLE_REVERSE,"074","CW Paddle Reverse", UiMenuDesc("Dit is Dah and Dah is Dit. Use if your keyer needs reverse meaning of the paddles.") },
    { MENU_CW, MENU_ITEM, MENU_CW_TX_RX_DELAY,"075","CW TX->RX Delay", UiMenuDesc("How long to stay in CW mode after stop sending a signal.") },
    { MENU_CW, MENU_ITEM, MENU_CW_OFFSET_MODE,"076","CW Freq. Offset", UiMenuDesc("TX: display is TX frequency if received frequency was zero-beated. DISP: display is RX frequency if received signal is matched to sidetone. SHIFT: LO shifts\, display is RX frequency if signal is matched to sidetone.") },
    { MENU_CW, MENU_ITEM, MENU_CW_AUTO_MODE_SELECT,"031","CW LSB/USB Select", UiMenuDesc("Set appropriate sideband mode for CW. If AUTO\, sideband is chosen for bands by its frequency. Long press on Mode button to get the other sideband mode")},
    { MENU_CW, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor confGroup[] =
{

    // Unused in firmware: { MENU_CONF, MENU_ITEM, CONFIG_FREQ_LIMIT_RELAX,"231","Freq. Limit Disable", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_FREQ_MEM_LIMIT_RELAX,"232","Save Out-Of-Band Freq.", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_TX_OUT_ENABLE,"207", "TX on Out-Of-Band Freq.", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_TX_DISABLE,"203","Transmit Disable", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_AUDIO_MAIN_SCREEN_MENU_SWITCH,"204","Menu SW on TX disable", UiMenuDesc(":soon:") },

    { MENU_CONF, MENU_ITEM, CONFIG_MUTE_LINE_OUT_TX,"205","TX Mute LineOut", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_TXRX_SWITCH_AUDIO_MUTE,"206","TX Initial Muting Time", UiMenuDesc("When switching from RX to TX the audio and HF output will be muted for roughly VALUE ms.") },
    { MENU_CONF, MENU_ITEM, CONFIG_MAX_VOLUME,"210","Max Volume", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_MAX_RX_GAIN,"211","Max RX Gain (0=Max)", UiMenuDesc(":soon:") },

    // UI Behavior / Key Beep
    { MENU_CONF, MENU_ITEM, CONFIG_BEEP_ENABLE,"212","Key Beep", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_BEEP_FREQ,"213","Beep Frequency", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_BEEP_VOLUME,"214","Beep Volume", UiMenuDesc(":soon:") },

    // USB CAT Related
    { MENU_CONF, MENU_ITEM, CONFIG_CAT_ENABLE,"220","CAT Mode", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_CAT_IN_SANDBOX,"530","CAT Running In Sandbox", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_CAT_XLAT,"400","CAT-IQ-FREQ-XLAT", UiMenuDesc(":soon:") },

    // Transverter Configuration
    { MENU_CONF, MENU_ITEM, CONFIG_XVTR_OFFSET_MULT,"280","XVTR Offs/Mult", UiMenuDesc("When connecting to a transverter\, set this to 1 and set the XVERTER Offset to the LO Frequency of it.") },
    { MENU_CONF, MENU_ITEM, CONFIG_XVTR_FREQUENCY_OFFSET,"281","XVTR Offset", UiMenuDesc("When transverter mode is enabled\, this value is added to the mcHF frequency after being multiplied with the XVTR Offs/Mult. Use Step+ to set a good step width\, much less turns with the dial knob if it is set to 1Mhz") },

    // Button Handling Setup
    { MENU_CONF, MENU_ITEM, CONFIG_STEP_SIZE_BUTTON_SWAP,"201","Step Button Swap", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_BAND_BUTTON_SWAP,"202","Band+/- Button Swap", UiMenuDesc(":soon:") },

    // mcHF Setup Calibration (Initial Setup, never to be changed unless HW changes)

    { MENU_CONF, MENU_ITEM, MENU_REVERSE_TOUCHSCREEN,"122","Reverse Touchscreen", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_VOLTMETER_CALIBRATION,"208","Voltmeter Cal.", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_FREQUENCY_CALIBRATE,"230","Freq. Calibrate", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_RF_FWD_PWR_NULL,"271","Pwr. Det. Null", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_FWD_REV_SENSE_SWAP,"276","FWD/REV ADC Swap.", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_80M_RX_IQ_GAIN_BAL,"240", "RX IQ Balance (80m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_80M_RX_IQ_PHASE_BAL,"241","RX IQ Phase   (80m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_10M_RX_IQ_GAIN_BAL,"242", "RX IQ Balance (10m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_10M_RX_IQ_PHASE_BAL,"243","RX IQ Phase   (10m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_80M_TX_IQ_GAIN_BAL,"250", "TX IQ Balance (80m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_80M_TX_IQ_PHASE_BAL,"251","TX IQ Phase   (80m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_10M_TX_IQ_GAIN_BAL,"252", "TX IQ Balance (10m)", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_10M_TX_IQ_PHASE_BAL,"253","TX IQ Phase   (10m)", UiMenuDesc(":soon:") },
    // { MENU_CONF, MENU_ITEM, CONFIG_AM_RX_GAIN_BAL,"244","AM  RX IQ Bal.", UiMenuDesc(":soon:") },
    // { MENU_CONF, MENU_ITEM, CONFIG_AM_RX_PHASE_BAL,"244b","AM  RX IQ Phase", UiMenuDesc(":soon:") },
    // { MENU_CONF, MENU_ITEM, CONFIG_FM_RX_GAIN_BAL,"245","FM  RX IQ Bal.", UiMenuDesc(":soon:") },
    //{ MENU_CONF, MENU_ITEM, CONFIG_AM_TX_GAIN_BAL,"254","AM  TX IQ Bal.", UiMenuDesc(":soon:") },
    //{ MENU_CONF, MENU_ITEM, CONFIG_FM_TX_GAIN_BAL,"255","FM  TX IQ Bal.", UiMenuDesc(":soon:") },

    // DSP Configuration, probably never touched
    { MENU_CONF, MENU_ITEM, CONFIG_DSP_NR_DECORRELATOR_BUFFER_LENGTH,"310","DSP NR BufLen", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_DSP_NR_FFT_NUMTAPS,"311","DSP NR FFT NumTaps", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_DSP_NR_POST_AGC_SELECT,"312","DSP NR Post-AGC", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_DSP_NOTCH_CONVERGE_RATE,"313","DSP Notch ConvRate", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_DSP_NOTCH_DECORRELATOR_BUFFER_LENGTH,"314","DSP Notch BufLen", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_DSP_NOTCH_FFT_NUMTAPS,"315","DSP Notch FFTNumTap", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_ITEM, CONFIG_AGC_TIME_CONSTANT,"320","NB AGC T/C (<=Slow)", UiMenuDesc(":soon:") },

    // Reset I2C Config EEPROM to empty state
    { MENU_CONF, MENU_ITEM, CONFIG_RESET_SER_EEPROM,"341","Reset Config EEPROM", UiMenuDesc(":soon:") },
    { MENU_CONF, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor powGroup[] =
{
    { MENU_POW, MENU_ITEM, CONFIG_TUNE_POWER_LEVEL,"P00","Tune Power Level", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_TUNE_TONE_MODE,"P99","Tune Tone (SSB)", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_REDUCE_POWER_ON_LOW_BANDS,"P0A","Reduce Power on Low Bands", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_CW_PA_BIAS,"260","CW PA Bias (If >0 )", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_PA_BIAS,"261","PA Bias", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_2200M_5W_ADJUST,"P01","2200m 5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_630M_5W_ADJUST,"P02","630m  5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_160M_5W_ADJUST,"P03","160m  5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_80M_5W_ADJUST,"P04","80m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_60M_5W_ADJUST,"P05","60m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_40M_5W_ADJUST,"P06","40m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_30M_5W_ADJUST,"P07","30m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_20M_5W_ADJUST,"P08","20m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_17M_5W_ADJUST,"P09","17m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_15M_5W_ADJUST,"P10","15m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_12M_5W_ADJUST,"P11","12m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_10M_5W_ADJUST,"P12","10m   5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_6M_5W_ADJUST,"P13","6m    5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_4M_5W_ADJUST,"P14","4m    5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_2M_5W_ADJUST,"P15","2m    5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_70CM_5W_ADJUST,"P16","70cm  5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_23CM_5W_ADJUST,"P17","23cm  5W PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_2200M_FULL_POWER_ADJUST,"O01","2200m Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_630M_FULL_POWER_ADJUST,"O02","630m  Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_160M_FULL_POWER_ADJUST,"O03","160m  Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_80M_FULL_POWER_ADJUST,"O04","80m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_60M_FULL_POWER_ADJUST,"O05","60m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_40M_FULL_POWER_ADJUST,"O06","40m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_30M_FULL_POWER_ADJUST,"O07","30m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_20M_FULL_POWER_ADJUST,"O08","20m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_17M_FULL_POWER_ADJUST,"O09","17m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_15M_FULL_POWER_ADJUST,"O10","15m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_12M_FULL_POWER_ADJUST,"O11","12m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_10M_FULL_POWER_ADJUST,"O12","10m   Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_6M_FULL_POWER_ADJUST,"O13","6m    Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_4M_FULL_POWER_ADJUST,"O14","4m    Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_2M_FULL_POWER_ADJUST,"O15","2m    Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_70CM_FULL_POWER_ADJUST,"O16","70cm  Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_23CM_FULL_POWER_ADJUST,"O17","23cm  Full PWR Adjust", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_2200M_ADJ,"C01","2200m Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_630M_ADJ,"C02","630m Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_160M_ADJ,"C03","160m Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_80M_ADJ,"C04","80m  Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_40M_ADJ,"C05","40m  Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_20M_ADJ,"C06","20m  Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_15M_ADJ,"C07","15m  Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_6M_ADJ,"C08","6m   Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_2M_ADJ,"C09","2m   Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_70CM_ADJ,"C10","70cm Coupling Adj.", UiMenuDesc(":soon:") },
    { MENU_POW, MENU_ITEM, CONFIG_FWD_REV_COUPLING_23CM_ADJ,"C11","23cm Coupling Adj.", UiMenuDesc(":soon:") },

    { MENU_POW, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor filterGroup[] =
{
    { MENU_FILTER, MENU_ITEM, MENU_FP_SSB_01,"600", "SSB Filter 1", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_SSB_02,"600", "SSB Filter 2", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_SSB_03,"600", "SSB Filter 3", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_SSB_04,"600", "SSB Filter 4", UiMenuDesc(":soon:") },

    { MENU_FILTER, MENU_ITEM, MENU_FP_CW_01,"600", "CW Filter 1", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_CW_02,"600", "CW Filter 2", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_CW_03,"600", "CW Filter 3", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_CW_04,"600", "CW Filter 4", UiMenuDesc(":soon:") },

    { MENU_FILTER, MENU_ITEM, MENU_FP_AM_01,"600", "AM Filter 1", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_AM_02,"600", "AM Filter 2", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_AM_03,"600", "AM Filter 3", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_AM_04,"600", "AM Filter 4", UiMenuDesc(":soon:") },

    { MENU_FILTER, MENU_ITEM, MENU_FP_SAM_01,"600", "SAM Filter 1", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_SAM_02,"600", "SAM Filter 2", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_SAM_03,"600", "SAM Filter 3", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, MENU_FP_SAM_04,"600", "SAM Filter 4", UiMenuDesc(":soon:") },

    { MENU_FILTER, MENU_ITEM, CONFIG_AM_TX_FILTER_DISABLE,"330","AM  TX Audio Filter", UiMenuDesc(":soon:") },
//    { MENU_FILTER, MENU_ITEM, CONFIG_SSB_TX_FILTER_DISABLE,"331","SSB TX Audio Filter", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_ITEM, CONFIG_SSB_TX_FILTER,"332","SSB TX Audio Filter2", UiMenuDesc(":soon:") },
    { MENU_FILTER, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};


const MenuDescriptor infoGroup[] =
{
    { MENU_SYSINFO, MENU_INFO, INFO_DISPLAY,"I01","Display", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_DISPLAY_CTRL,"I02","Disp. Controller", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_SI570,"I02","SI570", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_EEPROM,"I03","EEPROM", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_TP,"I04","Touchscreen", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_CPU,"I07","CPU", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_FLASH,"I07","Flash Size (kB)", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_RAM,"I08","RAM Size (kB)", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_FW_VERSION,"I08","Firmware", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_BUILD,"I08","Build", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_BL_VERSION,"I08","Bootloader", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_RFMOD,"I05","RF Bands Mod", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_INFO, INFO_VHFUHFMOD,"I06","V/UHF Mod", UiMenuDesc(":soon:") },
    { MENU_SYSINFO, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};

const MenuDescriptor debugGroup[] =
{
    { MENU_DEBUG, MENU_ITEM, MENU_DEBUG_TX_AUDIO,"028","TX Audio via USB", UiMenuDesc(":soon:") },
    { MENU_DEBUG, MENU_STOP, 0, "   " , NULL, UiMenuDesc("") }
};


MenuGroupState topGroupState;
MenuGroupState baseGroupState;
MenuGroupState confGroupState;
MenuGroupState powGroupState;
MenuGroupState filterGroupState;
MenuGroupState infoGroupState;
MenuGroupState cwGroupState;
MenuGroupState displayGroupState;
MenuGroupState debugGroupState;


const MenuGroupDescriptor groups[] =
{
    { topGroup, &topGroupState, NULL},  // Group 0
    { baseGroup, &baseGroupState, topGroup},  // Group 1
    { confGroup, &confGroupState, topGroup},  // Group 3
    { powGroup, &powGroupState, topGroup },  // Group 4
    { filterGroup, &filterGroupState, topGroup },  // Group 5
    { infoGroup, &infoGroupState, topGroup },  // Group 6
    { cwGroup, &cwGroupState, topGroup },  // Group 7
    { displayGroup, &displayGroupState, topGroup },  // Group 8
    { debugGroup, &debugGroupState, topGroup },  // Group 9
};
