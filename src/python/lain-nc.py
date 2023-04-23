#!/usr/bin/python
# -*- coding:utf-8 -*-
import sys
import os
picdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'pic')
libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)

import logging
from waveshare_epd import epd2in13b_V3
import time
from PIL import Image,ImageDraw,ImageFont
import traceback

logging.basicConfig(level=logging.DEBUG)

try:
    epd = epd2in13b_V3.EPD()
    # Init and Clear
    epd.init()
    epd.Clear()
    time.sleep(1)
    
    b_img = Image.new('1', (epd.height, epd.width), 255)  # 298*126
    r_img = Image.new('1', (epd.height, epd.width), 255)  # 298*126    
    layer_one = Image.open(os.path.join(picdir, 'lain-b.bmp')) # Black layer
    layer_two = Image.open(os.path.join(picdir, 'lain-r.bmp')) # Red layer
    b_img.paste(layer_one, (0,0))
    r_img.paste(layer_two, (0,0))
    epd.display(epd.getbuffer(b_img), epd.getbuffer(r_img))
except IOError as e:
    logging.info(e)
except KeyboardInterrupt:
    logging.info('ctrl+c:')
    epd2in13b_V3.epdconfig.module_exit()
    exit()

