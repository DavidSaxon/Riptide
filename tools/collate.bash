#!/bin/bash

../../ArcaneCollate/ArcaneCollate/build/linux_x86/arcanecollate --table_of_contents res/scry/resources.toc --page_size 4294967296 --collate_begin res/scry/gui/fonts.arccol res/scry/gui/fonts --collate_end
../../ArcaneCollate/ArcaneCollate/build/linux_x86/arcanecollate --table_of_contents res/core/resources.toc --page_size 4294967296 --collate_begin res/core/images.arccol res/core/images --collate_end

