namespace NB32
{
	class StateRegister
	{
		private:
			bool zero;
			bool negative;
			bool overflow;
			bool borrow;
			bool carry;
		public:
			StateRegister();
			bool isZero();
			bool isNegative();
			bool isOverflow();
			bool isBorrow();
			bool isCarry();
			void setZero(bool zero);
			void setNegative(bool negative);
			void setOverflow(bool overflow);
			void setBorrow(bool borrow);
			void setCarry(bool carry);
	};
}
