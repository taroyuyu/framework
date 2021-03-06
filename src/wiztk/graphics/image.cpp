/*
 * Copyright 2017 - 2018 The WizTK Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "image/private.hpp"

#include "pixmap/private.hpp"

namespace wiztk {
namespace graphics {

Image Image::MakeFromRaster(const Pixmap &pixmap) {
  Image image;
  image.p_->sk_image_sp = SkImage::MakeFromRaster(Pixmap::Private::Get(pixmap).sk_pixmap,
      nullptr,
      nullptr);

  return image;
}

Image::Image() {
  p_ = std::make_unique<Private>();
}

Image::Image(const Image &other) {
  p_ = std::make_unique<Private>(*other.p_);
}

Image::Image(Image &&other) noexcept {
  p_ = std::move(other.p_);
}

Image::~Image() = default;

Image &Image::operator=(const Image &other) {
  *p_ = *other.p_;
  return *this;
}

Image &Image::operator=(Image &&other) noexcept {
  p_ = std::move(other.p_);
  return *this;
}

} // namespace graphics
} // namespace wiztk
