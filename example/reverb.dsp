import("stdfaust.lib");
// Dattorro reverb with difusion parameters as per https://ccrma.stanford.edu/~dattorro/EffectDesignPart1.pdf
reverb(band_width, decay, damping) = re.dattorro_rev(0, band_width, 0.75, 0.625, decay, 0.7, 0.5, damping);

// Contols
//pre_delay_ctrl = hslider("Pre-delay", 30, 0, 200, 0.1);
band_width_ctrl = hslider("Band Width", 0.6, 0, 1, 0.001);
decay_ctrl = hslider("Decay", 0.8, 0, 1, 0.001);
damping_ctr = hslider("Damping", 0.25, 0, 1, 0.001);
dry_wet_ctr = hslider("Dry/Wet", 0.25, 0, 1, 0.001);

dry_wet_mix(mix, dry_l, dry_r, wet_l, wet_r) = (1-mix) * dry_l, (1-mix) * dry_r, mix * wet_l, mix * wet_r :> _,_;


process = _,_ <: _,_,reverb(band_width_ctrl, decay_ctrl, damping_ctr): dry_wet_mix(dry_wet_ctr);
