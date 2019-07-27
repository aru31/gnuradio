/* -*- c++ -*- */
/*
 * Copyright 2006,2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ANALOG_AGC3_CC_H
#define INCLUDED_ANALOG_AGC3_CC_H

#include <gnuradio/analog/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace analog {

    /*!
     * \brief high performance Automatic Gain Control class with
     * attack and decay rates.
     * \ingroup level_controllers_blk
     *
     * \details
     * Unlike the AGC2 loop, this uses an initial linear calculation
     * at the beginning for very fast initial acquisition. Moves to
     * IIR model for tracking purposes.
     *
     * For Power the absolute value of the complex number is used.
     */
    class ANALOG_API agc3_cc : virtual public sync_block
    {
    public:
      // gr::analog::agc3_cc::sptr
      typedef boost::shared_ptr<agc3_cc> sptr;

      /*!
       * Build a complex value AGC loop block with attack and decay rates.
       *
       * \param attack_rate the update rate of the loop when in attack mode.
       * \param decay_rate the update rate of the loop when in decay mode.
       * \param reference reference value to adjust signal power to.
       * \param gain initial gain value.
       * \param iir_update_decim stride by this number of samples before
       *                         computing an IIR gain update
       */
      static sptr make(float attack_rate = 1e-1, float decay_rate = 1e-2,
                       float reference = 1.0, float gain = 1.0, int iir_update_decim=1);

      virtual float attack_rate() const = 0;
      virtual float decay_rate() const = 0;
      virtual float reference() const = 0;
      virtual float gain() const = 0;
      virtual float max_gain() const = 0;

      virtual void set_attack_rate(float rate) = 0;
      virtual void set_decay_rate(float rate) = 0;
      virtual void set_reference(float reference) = 0;
      virtual void set_gain(float gain) = 0;
      virtual void set_max_gain(float max_gain) = 0;
    };

  } /* namespace analog */
} /* namespace gr */

#endif /* INCLUDED_ANALOG_AGC3_CC_H */

/* ! BlockTool
input_signature: make
input_min_streams: 1
input_max_streams: 1
input_sizeof_stream_item: sizeof(gr_complex)
output_signature: make
output_min_streams: 1
output_max_streams: 1
output_sizeof_stream_item: sizeof(gr_complex)
message_input: 
message_output: 
EndTool !*/
