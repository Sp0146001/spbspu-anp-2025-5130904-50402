#include <iostream>
namespace petrov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& pos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& center, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };

  Rectangle::Rectangle(const point_t& center, double width, double height):
    center_(center),
    width_(width),
    height_(height)
  {
    if (width_ <= 0.0 || height_ <= 0.0)
    {
      throw std::invalid_argument("Ошибка: ширина и высота должны быть положительными");
    }
  }
  double Rectangle::getArea() const
  {
    return width_ * height_;
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    return {width_, height_, center_};
  }
  void Rectangle::move(const point_t& pos)
  {
    center_ = pos;
  }
  void Rectangle::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }
  void Rectangle::scale(double k)
  {
    if (k <= 0.0)
    {
      throw std::invalid_argument("Ошибка: коэффициент масштабирования должен быть положительным");
    }
    width_ *= k;
    height_ *= k;
  }
  class Diamond : public Shape
  {
  public:
    Diamond(const point_t& center, double diag_h, double diag_v);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t center_;
    double diag_h_;
    double diag_v_;
  };

  Diamond::Diamond(const point_t& center, double diag_h, double diag_v):
    center_(center),
    diag_h_(diag_h),
    diag_v_(diag_v)
  {
    if (diag_h_ <= 0.0 || diag_v_ <= 0.0)
    {
      throw std::invalid_argument("Ошибка: диагонали должны быть положительными");
    }
  }

  double Diamond::getArea() const
  {
    return (diag_h_ * diag_v_) / 2.0;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return {diag_h_, diag_v_, center_};
  }

  void Diamond::move(const point_t& pos)
  {
    center_ = pos;
  }

  void Diamond::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void Diamond::scale(double k)
  {
    if (k <= 0.0)
    {
      throw std::invalid_argument("Ошибка: коэффициент масштабирования должен быть положительным");
    }
    diag_h_ *= k;
    diag_v_ *= k;
  }
}
int main() {
  return 0;
}
